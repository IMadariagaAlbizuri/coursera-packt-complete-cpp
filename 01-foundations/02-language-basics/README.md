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