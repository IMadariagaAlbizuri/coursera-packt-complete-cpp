# Move semantics

## L-values and R-values

| | L-value | R-value |
|---|---|---|
| Name | Has a name | Has no name |
| Lifetime | Persists beyond the expression | Temporary, lost at the end of the expression |
| Assignment | Can be assigned values | Cannot be assigned values |
| Variables | All the variables | Literals and temporaries |
| Functions | Returning by reference | Returning by value |

```cpp
int x = 10;   // x is an l-value, 10 is an r-value
```

Some expressions return l-values and others r-values, and we can create references to both.

## R-value references

An r-value reference is bound to a temporary and represents a temporary value. It is created with the `&&` operator.

```cpp
int &&r1 = 10;        // literal
int &&r2 = Add(5, 8); // Add returns by value, so it is a temporary
int &&r3 = 7 + 2;     // the expression returns a temporary
```

An r-value reference cannot be bound to an l-value, and an l-value reference is always bound to an l-value.

```cpp
int x = 10;
int &&r4 = x;         // error
```

## Copy and move semantics

A copy of an object is created through the copy constructor. For classes with pointers or other resources it has to be a deep copy: allocate new memory and copy the content.

But sometimes the copy is made from a temporary. For example, a function that returns an object by value creates a copy when it returns. Copying the content of something that is going to disappear is a waste, so we can move the state from the source object to the target instead. That is move semantics.

```cpp
// copy: Object2 allocates its own memory
// move: Object2 takes the address of Object1, and Object1 is left empty
```

In a move, the target points to the same address as the source, like a shallow copy. It is safe because the source is a temporary. It is important to set the pointer of the source to `nullptr` afterwards, otherwise both would release the same memory.

### Copy or move?

If an expression yields a temporary that has to be copied into another object, we do a move.

By default the copy constructor would be called, with the temporary as the argument. To detect the temporary we implement a constructor that takes an r-value reference. That is the move constructor.

syntax: `<name>(<name> &&other);`

```cpp
Integer::Integer(Integer &&other) {
    value = other.value;     // take the address
    other.value = nullptr;   // leave the source empty
}
```

The compiler chooses by the argument: a temporary goes to the move constructor, an l-value goes to the copy constructor.

# Rule of 5 & Rule of 0

Some classes may own some kind of resource, such as a pointer, file handle, socket, thread, etc.

These resources are usually acquired by the class in the constructor.

Subsequently, we have to decide what to do in case the object that holds the resource is **copied, moved or destroyed**. We must make sure these cases are handled correctly, and to do so we follow the Rule of 5.

## Rule of 5

If a class has **ownership semantics**, you must provide a user-defined:

1. Destructor
2. Copy constructor
3. Copy assignment operator
4. Move constructor
5. Move assignment operator

This is required so that the underlying resource is correctly handled in the different class operations.

## Rule of 0

What if the class does not have ownership semantics (it does not acquire any resource)?

In that case, we should **not** implement any of the five functions. This is known as the Rule of 0.

Since we don't provide any of the five, the compiler automatically synthesizes the necessary ones.

If we provide a user-defined implementation of some of them, the compiler may not synthesize the others.

## Special member functions: what the compiler generates

Each row is the function **you** define (**Custom**); each column shows what happens to the other special member functions.

| You define \ Result    | Copy Constructor | Copy Assignment | Move Constructor | Move Assignment | Destructor |
|------------------------|:----------------:|:---------------:|:----------------:|:---------------:|:----------:|
| **Copy constructor**   | Custom           | `=default`      | `=delete`        | `=delete`       | `=default` |
| **Copy assignment**    | `=default`       | Custom          | `=delete`        | `=delete`       | `=default` |
| **Move constructor**   | `=delete`        | `=delete`       | Custom           | `=delete`       | `=default` |
| **Move assignment**    | `=delete`        | `=delete`       | `=delete`        | Custom          | `=default` |
| **Destructor**         | `=default`       | `=default`      | `=delete`        | `=delete`       | Custom     |
| **None**               | `=default`       | `=default`      | `=default`       | `=default`      | `=default` |

> **Note:** In the standard, the `=delete` entries in the copy constructor, copy assignment and destructor rows actually mean the compiler **does not declare** the move operations, so `std::move` silently falls back to a copy. Only when you define a move constructor or move assignment are the copy operations truly deleted.

## Copy Elision

Copy elision is an optimization where the compiler **eliminates unnecessary copies or moves of temporary objects**, constructing the object directly in its final destination.

Compilers apply it by default whenever a temporary value is involved.

```cpp
Integer Create() {
    return Integer{5};   // temporary built directly in the caller's variable
}

Integer a = Create();    // no copy or move constructor is called
```

- **Since C++17** it is **mandatory** when initializing from a temporary (a prvalue), as in the example above. The copy/move constructor doesn't even need to exist.
- **Returning a named local variable** (NRVO) is still *optional*, although compilers usually do it.
- Elision can change the output: the constructor/destructor messages from the copy or move simply don't appear.
- Don't write `return std::move(local);`. It blocks elision, so just `return local;`.
- To see what would happen without it, GCC/Clang have `-fno-elide-constructors` (for pre-C++17 behavior).

## std::move Function

`std::move` is a library function, normally used with **lvalues**. It doesn't move anything by itself: it **casts** the object to an rvalue reference, so the compiler picks the move operations (move constructor / move assignment) instead of the copy ones.

Example:

```cpp
int main(){
    Integer a(1);
    auto b{a};              // Always uses the copy constructor
    return 0;
}
```

To avoid the copy, we use `std::move`:

```cpp
int main(){
    Integer a(1);
    auto b{std::move(a)};   // Now the object is moved, not copied
    return 0;
}
```

After the move, `a` is left in a **valid but unspecified state** (in our `Integer`, `m_pInt` is `nullptr`). Don't use it again, except to assign it a new value or let it be destroyed.

### Why move an object instead of copying it?

There are two reasons:

1. **To hand over an object to a function and release its resources afterwards.**

```cpp
void Print(Integer value){}

int main(){
    Integer a(1);
    Print(std::move(a));    // The parameter takes the resource; it is released when Print ends
    return 0;
}
```

This is a common pattern with `std::unique_ptr`, and it is used extensively in C++.

2. **To work with non-copyable objects.** A non-copyable object has no copy operations, only move operations.

Why create this kind of class? Because it may contain members that cannot be copied, for example file streams (`std::ofstream`) or `std::unique_ptr`.