# Operator overloading

Operator overloading lets us give custom behaviour to the built-in operators for **user-defined types**, so objects can be used with a natural notation (`a + b`, `std::cout << a`).

An overloaded operator is just a function named `operator<symbol>`:

```cpp
<return type> operator<symbol>(<parameters>)

Integer a(1), b(2);
Integer c = a + b;   // a.operator+(b)  or  operator+(a, b) if global
```

## Global vs member

| | Global function | Member function |
|---|---|---|
| Parameters | as many as operands | left operand is implicit (`this`) |
| Binary operator | 2 parameters | 1 parameter |
| Unary operator | 1 parameter | 0 parameters |

```cpp
Integer operator+(const Integer &, const Integer &);   // global
Integer Integer::operator+(const Integer &) const;     // member
```

Use a **global** function when the left operand is not your class (`5 + a`, `std::cout << a`). If it needs private data, declare it `friend` inside the class.

## Rules

1. Arity, precedence and associativity cannot be changed.
2. Member operators are non-static (except `new` and `delete`).
3. At least one operand must be a user-defined type (you can't redefine `int + int`).
4. If the left operand is a primitive type, the operator must be global.
5. Not overloadable: `::`, `.`, `.*`, `?:`, `sizeof`.
6. You can only overload existing operators, not invent new ones.
7. Keep the conventional meaning, or users of your class will be confused.

## Common operators

```cpp
Integer& operator++();        // prefix  ++a
Integer  operator++(int);     // postfix a++  (dummy int)

std::ostream& operator<<(std::ostream &out, const Integer &obj);  // global, usually friend
std::istream& operator>>(std::istream &in, Integer &obj);          // global, usually friend
```

Both stream operators return the stream so they can be chained. In `>>`, read into a local variable first and then store it in the object.

## Smart pointers and RAII

**RAII (Resource Acquisition Is Initialization):** tie the lifetime of a resource to the lifetime of a local object. When the object is destroyed, its destructor releases the resource, so there are no leaks even if an exception is thrown.

A smart pointer is an RAII class that behaves like a pointer, which it achieves by overloading `->` and `*`:

```cpp
class IntPtr {
    Integer *m_p;
public:
    IntPtr(Integer *p) : m_p(p) {}
    ~IntPtr() { delete m_p; }
    Integer* operator->() { return m_p; }
    Integer& operator*()  { return *m_p; }
    IntPtr(const IntPtr&) = delete;             // avoid double delete
    IntPtr& operator=(const IntPtr&) = delete;
};
```

The standard library (`<memory>`) already provides them:

- `std::unique_ptr`: **sole** owner. Can't be copied, only moved (`std::move`). After the move, the original is `nullptr`, so don't use it.
- `std::shared_ptr`: **shared** ownership with a reference count. The resource is freed when the count reaches 0.

Prefer `std::make_unique<T>()` / `std::make_shared<T>()` over `new`, and smart pointers over raw owning pointers.

# Type conversions

A type conversion turns a value of one type into another. It can be **implicit** (done by the compiler) or **explicit** (a cast written by the programmer). It can happen between basic↔basic, basic↔user-defined, user-defined↔basic and user-defined↔user-defined.

```cpp
int a = 5, b = 2;
float f = a;                 // implicit: int -> float
float m = a / b;             // 2, NOT 2.5: the division is done in int first
float k = static_cast<float>(a) / b;   // 2.5
```

## C++ casts

| Cast | Use |
|---|---|
| `static_cast` | Well-defined, compile-time checked conversions (`int`→`float`, constructors, conversion operators). |
| `reinterpret_cast` | Reinterprets bits between unrelated types (`int*`→`char*`). Dangerous. |
| `const_cast` | Adds or removes `const`. Writing to an originally `const` object is undefined behaviour. |
| `dynamic_cast` | Safe downcasts in polymorphic hierarchies, checked at run time. |

Always prefer C++ casts to C-style casts `(float)a`: they are more restrictive, show intent and are easy to search for.

## Primitive → user-defined

A **converting constructor** (callable with one argument) takes part in implicit conversion:

```cpp
Integer a{5};   // direct initialization
Print(5);       // implicit: creates a temporary Integer(5)
a = 7;          // temporary Integer(7), then move assignment
```

Mark it `explicit` to forbid this: `explicit Integer(int value);`. Then `Integer a{5}` still works, but `Print(5)` and `a = 7` don't compile.

## User-defined → primitive

Use a **conversion operator**. It has no return type and no parameters (the target type is in the name), and should be `const`:

```cpp
operator int() const;
int v = static_cast<int>(a1);
```

## User-defined → user-defined

Either a converting constructor in the destination class, or a conversion operator in the source class:

```cpp
operator Integer() const { return m_Id; }   // in Product
Integer id = p3;                            // p3.operator Integer()
```

# Initialization vs assignment

```cpp
Integer a{5};     // initialization
Integer b;        // default construction...
b = 6;            // ...then assignment
```

| Initialization | Assignment |
|---|---|
| `Integer(int)` | `Integer()` |
| `~Integer()` | `Integer(int)` (temporary from `6`) |
| | `operator=(Integer&&)` |
| | `~Integer()` (temporary) |
| | `~Integer()` |

Assignment needs more calls. **Prefer initialization.**

## Member initializer list

It initializes members directly in the constructor, avoiding default construction + assignment. Members are initialized in the order they are **declared in the class**, not the order in the list.

```cpp
class Product {
    Integer m_Id;
    int x;
public:
    Product(const Integer &id) : m_Id(id), x(id.GetValue()) {
        std::cout << "Product(const Integer &)" << std::endl;
    }
    ~Product() { std::cout << "~Product()" << std::endl; }
};
```