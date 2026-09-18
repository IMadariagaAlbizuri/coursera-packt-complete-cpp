# First C++ Program

A C++ program consists of source files: header files (`.h` / `.hpp`) and implementation files (`.cpp`).

## Comments

```cpp
// Single line comment
/* Multiline comment */
```

## Header files

The standard library is split into header files, and we include the ones we need with `#include`. For our first exercise we will be using `<iostream>`, which allows us to print a message on the terminal.

```cpp
#include <iostream>
```

## Namespaces

A namespace is a way to wrap types, so that they are not visible outside. The elements of `<iostream>`, such as `cout`, live inside `std`, so first we have to open it.

```cpp
using namespace std;   // opens the whole namespace
std::cout              // or write the full name, no using needed
```

## Printing

`cout` represents the computer screen. To insert anything into it we use the `<<` operator, the **insertion operator**. Several of them in one statement is a **cascade of operators**.

```cpp
cout << "Hello" << " " << "C++" << endl;
```

To print a new line we use `endl`, a **manipulator**: it does not print text, it affects the output.

Also, at the end of every statement we need to use `;`.

# Primitives and Variables

## Primitive types

- **Arithmetic** → integral & floating point
  - **Integral** → `bool`, `char`, `wchar_t`, `char16_t`, `char32_t`, `short`, `int`, `long`
  - **Floating point** → `float` and `double`
- **void** → special type used in certain cases (pointers and functions)

**Modifiers** change the meaning of a type: `signed`, `unsigned`, `short` and `long`. Not all types can be modified — `signed` and `unsigned` only work on integral ones.

Types can also be qualified with **qualifiers**, such as `const` or `volatile`.

## Datatype size

| Type | Size |
|------|------|
| `bool`, `char` | 1 byte |
| `wchar_t`, `short` | 2 bytes |
| `int`, `long`, `float` | 4 bytes |
| `long long`, `double`, `long double` | 8 bytes |

The minimum and maximum value a type can hold is called its **range**. `<climits>` gives it for the integral types, `<cfloat>` for the floating point ones.

> [!NOTE]
> These sizes are the usual ones, not a guarantee: they change with the compiler and the platform.
> Use `sizeof(type)` to check.

## Variable declaration

A variable is declared by specifying a type followed by a variable name. It is a good practice to initialize it.

```cpp
int i;
int a, b, c;        // multiple variables of the same type
int j = 0;
int k{0};           // uniform initialization, C++11
```

## Arrays

An array holds a fixed number of elements of the same type. The size is part of the type, so it has to be known at compile time and cannot change later.

```cpp
int arr[5];                     // uninitialized array of 5 integers
int arr2[5] = {1, 2, 3, 4, 5};  // initialized array of 5 integers
int arr3[] = {1, 2, 3};         // size deduced from the values: 3

arr2[0];                        // access by index, first element is 0
```

> [!WARNING]
> Going out of the bounds of an array is not an error, it is undefined behaviour: `arr2[7]` reads
> whatever is in that memory.
 

# Input and Output Classes

Two classes for input and output: `std::basic_istream` and `std::basic_ostream`. For convenience, `std::istream` and `std::ostream`.

- **`std::cout`** → the console. Insert into it with `<<` (**insertion operator**).
- **`std::cin`** → the keyboard. Extract from it with `>>` (**extraction operator**).

```cpp
int age;
std::cout << "Your age: ";
std::cin >> age;
```

Both are declared in `<iostream>`.

# Functions

A function is a set of statements enclosed within a pair of curly braces `{}`, called the body of the function. The statements define what the function does.

Every function has a unique name, and it is used to invoke or call the function.

Functions help us to avoid repetitive code in the program. They can be reused in different parts of the program and can be called with no limit.

It can accept values as inputs, called parameters in the declaration and arguments when we call it. Then the function can process them and return the result as the return value.

syntax: `<return type> <name>(<parameters (optional)>)`

```cpp
int Add(int a, int b) {
    return a + b;
}
```

When the function does not return anything, we specify it with the type `void`.

# Headers

When we use a function, the compiler needs to know that the function exists before we call it. This is done with a function prototype, which is a declaration that tells the compiler the name of the function, its return type and its parameters.

A declaration is only a promise, it has no body. The definition is the one that contains the statements and does the actual work.

syntax: `<return type> <name>(<parameters>);`

```cpp
int Multiply(int x, int y);
```

When the function is defined in another file, we write its prototype in a header file `.h` and we bring it into our file with the `#include` directive.

`#include` is not an import. The preprocessor copies and pastes the content of the header at that point, so after the preprocessing it is exactly the same as if we had written the prototype by hand.

Declarations go in the `.h` file, because it is copied into every file that includes it. Definitions go in the `.cpp` file, because they must exist only once in the whole program.

It is a good practice to include the header in its own `.cpp` file too. This way the compiler sees the declaration and the definition together and it tells us immediately if they do not match.

# Uniform initialization

Uniform initialization is a way of initializing a variable using curly braces `{}`. It works the same for primitives, arrays, pointers and user defined types, and that is where the name comes from.

syntax: `T obj{};`

## Value initialization

With empty braces the variable takes its default value, which is `0` for the numeric types.

```cpp
int a{};                   // 0
char c[8]{};               // every element is '\0'
int* p1 = new int{};       // 0
char* p2 = new char[8]{};  // every element is '\0'
```

## Direct initialization

With a value inside the braces the variable is initialized with that value.

```cpp
int b{5};
std::string s{"C++"};
char e[8]{"Hello"};
```

## Aggregate initialization

Arrays can be initialized element by element. The elements that we do not write are value initialized.

```cpp
char d[8]{'a', 'b', 'c', 'd'};
```

## Copy initialization

It is the classic one, the one with the `=` sign. It is not uniform initialization, but it is useful to compare.

```cpp
int a1 = 0;
```

## Most vexing parse

`int b2();` does not create a variable initialized to zero. The compiler reads it as the declaration of a function called `b2` that takes no parameters and returns an `int`. With braces, `int b2{};`, there is no ambiguity.

## Advantages

1. It forces the initialization, so we never read a variable with garbage in it.
2. It works with array types, where direct initialization with parentheses is not allowed.
3. It prevents narrowing conversions, like assigning a floating point value to an integer.

```cpp
int x{3.14};   // error
int y = 3.14;  // compiles, the value is truncated to 3
```

Note: for the primitive types we normally use the assignment `=`, but for the user defined types we use uniform initialization.

# Pointers

A pointer is a variable that holds the memory address of another variable. It gives indirect access: we reach the value through the address instead of the name.

It is declared with the `*` operator, and its type must match the type it points to. To get the address of a variable we use `&`.

```cpp
int x = 10;
int *ptr = &x;
int *p1, *p2;   // the * belongs to each variable, not to the type
```

It needs not to be initialized, but always do it: an uninitialized pointer holds garbage and using it crashes the program.

A `void*` can hold the address of any type, but it has to be casted back before reading the value.

## Dereference operator

The `*` operator accesses the value at the address, for both reading and writing.

```cpp
*ptr = 5;        // write: now x is 5
int y = *ptr;    // read: y takes the value of x
```

The same symbol means two things: the type in a declaration, and the dereference in an expression.

## Null pointer

A pointer that points to nothing, used to initialize a pointer when we still have no address for it.

```cpp
int *p1 = nullptr;   // C++11
int *p2 = NULL;      // old C style, defined as 0
```

Dereferencing it crashes the program, and that is exactly why it is useful: `nullptr` is a value we can check with an `if`, and garbage is not.

```cpp
if (ptr != nullptr) {
    std::cout << *ptr << std::endl;
}
```
# References

A reference is an alternative name for a variable, an alias. It is created with the `&` operator and it always needs an initializer, called the referent.

```cpp
int x = 10;
int &ref = x;   // x is the referent, ref is the reference
```

It is not a new variable, just another name for the same memory. Modifying one modifies the other, and both have the same address.

Once bound to its referent it stays bound forever, it cannot point to another variable.

The initializer must be an l-value, something with a name and an address. `int& r = 10;` is an error, but `const int& r = 10;` is fine.

Their main use is passing variables to functions without copying them.

```cpp
void Increment(int n)  { n++; }   // modifies the copy
void Increment(int& n) { n++; }   // modifies the original
```

## Difference between pointer and reference

| | Reference | Pointer |
|---|---|---|
| Initializer | Always needed | Optional |
| Initializer must be l-value | Yes | No |
| Can be null | No | Yes, `nullptr` |
| Can be reseated | No | Yes |
| Storage | Same address as the referent | Has its own |
| Dereference | Not needed | Needs `*` |

# Const qualifier

It makes the value of a variable constant, so it cannot be changed afterwards. A `const` variable must always be initialized in the declaration.

syntax: `const <type> <name>{<initializer>};`

```cpp
const float PI{3.14f};
PI = 3;              // error
const int a;         // error, no initializer
```

It replaces the macros of C, which are not type safe and have no scope.

It is most commonly used with references, to pass a variable to a function without copying it and without allowing the function to modify it.

```cpp
void Print(const std::string& s);
```

# Auto keyword

In C it was used to indicate automatic storage for a variable declared inside a function block, and it was optional. Now it is used to declare a variable without specifying its type, which the compiler deduces from the initializer.

syntax: `auto <identifier> = <initializer>;`

The initializer can be a literal, an expression or a function call that returns a value. It is mandatory, because without it the compiler has nothing to deduce from.

```cpp
auto a = 5;                // int
auto c = Multiply(2, 3);   // whatever Multiply returns
auto x;                    // error
```

They are really useful when lambda expressions and templates are used, where the type is long or cannot be written by hand.

# Range-based for loop

It allows iterations over arrays and containers with no need of an index variable. Each iteration returns an element, and it can be used with any object that behaves like a range.

syntax: `for (<variable declaration> : <range>)`

```cpp
int arr[]{1, 2, 3};

for (int x : arr) {}     // x is a copy, modifying it does not change arr
for (int& x : arr) {}    // with a reference we can modify the elements
```

The size of the range must be known, so it does not work with an array received as a function parameter.

Difference between the for loop and the range-based for loop:

## For vs range-based for

| | For loop | Range-based for loop |
|---|---|---|
| Iteration | Index based | Does not use an index |
| End condition | Written by us | Provided by the range |
| Increment | The index needs to be incremented or decremented | Not needed |
| Errors | More likely | Less chances |
| Control | More control over the iterations | No control |

# Function overloading

When we have the same logical operation but with different parameters, it is better to overload the function instead of using a different name for each one. The code is easier to read, because we only have to remember one name.

Functions with the same name must differ in the number or in the type of their parameters. This is called the signature.

```cpp
int Add(int a, int b);
double Add(double a, double b);
int Add(int a, int b, int c);
```

The correct implementation is chosen based on the arguments of the call, and it is resolved at compile time.

The return type is not part of the signature, so these two do not overload, they are an error.

```cpp
int Add(int a, int b);
double Add(int a, int b);   // error
```

If no version matches exactly the compiler tries a conversion, and if more than one matches equally well it is an ambiguity error.

# Default function arguments

They allow to assign default values to some of the arguments, so it becomes optional for the caller
to pass them. If a value is not passed, the default one is used, which makes the function more
convenient to use.

```cpp
void CreateWindow(const char* title, int x = -1, int y = -1, int width = -1, int height = -1);

CreateWindow("Hello");           // uses all the defaults
CreateWindow("Hello", 10, 20);   // x and y are given, the rest are defaults
```

# Inline functions

Calling a function has a cost: the assembler has to jump to it, pass the arguments and come back. When the function is very small this overhead can be bigger than the work itself.

With `inline` we ask the compiler to replace the call with the body of the function, so the jump disappears.

```cpp
inline int Square(int x) {
    return x * x;
}
```
> [!WARNING]
> Inlining increases the binary size, because the body is copied at every call. Use it only for very small functions.

## Macros

A macro is the old C way of doing this. It is defined with `#define`, and the preprocessor replaces the text before the compiler sees the file.

```cpp
#define SQUARE(x) x * x
```

The preprocessor does not know anything about C++, it only pastes text. That is why `SQUARE(2 + 3)` becomes `2 + 3 * 2 + 3`, which is 11 and not 25.

In C++ we use `inline` functions instead, which do the same but with the rules of the language.

## Macro vs inline function

| | Macro | Inline function |
|---|---|---|
| How it works | Text substitution | The call is replaced with the body |
| Safety | Error prone, because of the substitution | Safe, it has function semantics |
| Address | Does not have one | Has one |
| Multiple lines | Difficult to use | No problem |
| Class members | Cannot be used | Can be inline |

# Function pointers

A pointer that holds the address of a function. Its type is the signature of the function, which means the return type and the arguments.

It can be used to invoke the function indirectly, even if the name of the function is not known.

syntax: `<return type> (*<name>)(<arguments>) = &<function>;`

```cpp
int Add(int a, int b);

int (*PtrAdd)(int, int) = &Add;

int result = PtrAdd(2, 3);     // call through the pointer
int result = (*PtrAdd)(2, 3);  // the same, the * is optional
```

The parentheses around `*PtrAdd` are needed. Without them, `int *PtrAdd(int, int)` is the declaration of a function that returns an `int*`.

With `auto` we do not have to write the type: `auto PtrAdd = &Add;`.

# Namespaces

A namespace is a name region where we can declare any C++ type. Everything declared inside it is not visible outside unless we ask for it.

We have already used one: `std` is the namespace of the standard library.

They are used to prevent name clashes, and also to modularize the code, grouping classes and functions that belong together.

```cpp
namespace Geometry {
    const double PI{3.14159};
    double CircleArea(double r);
}
```

Namespaces can be nested.

To access a type inside a namespace we have three options:

```cpp
Geometry::CircleArea(2.0);   // full name, no using needed
using Geometry::CircleArea;  // brings only this name into the scope
using namespace Geometry;    // opens the whole namespace
```

> [!WARNING]
> Opening a namespace globally is not a good practice, because all its classes, variables and functions become visible and the name clashes come back. Never do it in a header file.