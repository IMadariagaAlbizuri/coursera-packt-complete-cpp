# Memory Management II

How `std::shared_ptr` and `std::weak_ptr` work internally.

## std::shared_ptr & std::weak_ptr

### The control block

When we create a shared pointer:

```cpp
std::shared_ptr<int> p{new int{5}};
```

a **control block** is created alongside the managed object. It stores:

- The **strong reference count**: the number of `shared_ptr`s owning the object.
- The **weak reference count**: the number of `weak_ptr`s observing it.
- The deleter (and allocator), if any.

### Creating a weak_ptr

A `weak_ptr` is always created from a `shared_ptr` (or from another `weak_ptr`):

```cpp
std::weak_ptr<int> wk = p;
```

It points to the same control block, so it can see the reference counts, but it does **not** own the object and does **not** increase the strong count.

### Lifetime rules

- When the strong count reaches zero (e.g. after `p.reset()`), the **managed object is destroyed** and its memory released.
- The **control block stays alive** as long as at least one `weak_ptr` still refers to it.
- When the weak count also reaches zero, the control block is destroyed.

### Why is this useful?

A `weak_ptr` cannot access the object directly (no `operator*` or `operator->`). It lets us *safely check* whether the object still exists, and only then use it.

- **`expired()`**: returns `true` if the strong count is zero (the object is gone), `false` if at least one `shared_ptr` still owns it.
- **`lock()`**: returns a `shared_ptr` to the object. If the object is still alive, the strong count is incremented by one while that `shared_ptr` exists. If it has expired, it returns an **empty** `shared_ptr`.

```cpp
if (auto sp = wk.lock()) {
    std::cout << *sp << '\n';   // safe: sp keeps the object alive
} else {
    std::cout << "Object no longer exists\n";
}
```

> **Tip:** Prefer calling `lock()` and checking the result over calling `expired()` and then `lock()`. In multithreaded code the object could be destroyed between the two calls, while `lock()` does the check and the acquisition atomically.

### Typical use case

`weak_ptr` is used to **break circular references** between `shared_ptr`s (e.g. parent <-> child), and for caches or observers that must not keep an object alive.

## Circular References

### The problem

If two objects hold `shared_ptr`s to each other, they keep each other alive forever. Each object's strong count never reaches zero, so neither is destroyed and the memory leaks.

```cpp
struct B;

struct A {
    std::shared_ptr<B> b;
    ~A() { std::cout << "A destroyed\n"; }
};

struct B {
    std::shared_ptr<A> a;   // A <-> B: circular reference
    ~B() { std::cout << "B destroyed\n"; }
};

int main() {
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();
    a->b = b;
    b->a = a;
}   // nothing is printed: neither destructor runs
```

Reference counts:

| After...                  | A strong count | B strong count |
|---------------------------|:--------------:|:--------------:|
| creating `a` and `b`      | 1              | 1              |
| `a->b = b; b->a = a;`     | 2              | 2              |
| end of `main` (locals die)| 1              | 1              |

The two local variables are gone, but each object is still owned by the other, so the counts stop at 1 and never reach 0. Nobody can reach these objects anymore, yet they are never freed.

### The solution: `weak_ptr`

Break the cycle by making one of the two links a `weak_ptr`. A `weak_ptr` does not increase the strong count, so it does not keep the object alive.

```cpp
struct B {
    std::weak_ptr<A> a;     // weak link: does not own A
    ~B() { std::cout << "B destroyed\n"; }
};
```

Now the counts are A = 1 and B = 2 after linking. When `main` ends:

1. `b` is destroyed, so B's count goes 2 -> 1.
2. `a` is destroyed, so A's count goes 1 -> 0 and **A is destroyed**.
3. A releases its `shared_ptr<B>`, so B's count goes 1 -> 0 and **B is destroyed**.

Output:

```
A destroyed
B destroyed
```

To use the weak link, go through `lock()` (see above):

```cpp
if (auto sp = b->a.lock()) {
    // A is still alive, sp keeps it alive while we use it
}
```

### Rule of thumb

- The **owner** (parent) holds a `shared_ptr` to the child.
- The **back-reference** (child -> parent) holds a `weak_ptr`.
- Use the same idea for observers and caches, which should not extend an object's lifetime.
