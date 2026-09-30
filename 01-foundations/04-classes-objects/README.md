# Object Oriented Programming

It uses objects as the fundamental building block instead of algorithms. The program is a collection of objects, and every object is an instance of some class.

Classes are related through inheritance, and objects through containment.

It allows us to simulate the interaction of objects in real-world systems, representing the objects of the problem domain. This reduces the complexity and makes the code reusable.

The object model has four basic principles:

1. Abstraction
2. Encapsulation
3. Inheritance
4. Polymorphism

## Abstraction

It focuses on the important and necessary details, and leaves out the unwanted ones. For a person it could be the name or the weight. Which characteristics matter depends on the problem domain.

## Encapsulation

It hides the implementation details: the class provides a behaviour without revealing how it is done. The client does not see the internal implementation, so it is easy to use and the programmer can change it without breaking anything. It is implemented through access modifiers.

## Inheritance

It creates a hierarchy of classes related through an "is-a" relationship, because they share the same behaviour. A dog is an animal.

The children inherit the behaviour and its implementation from the parent. They can reuse it as it is or provide a different implementation. It promotes reuse and extensibility.

## Composition

The other way of reuse. It is a relationship between objects, "has-a" or "part-of". A car has an engine.

| | Inheritance | Composition |
|---|---|---|
| Relationship | is-a | has-a |
| Between | Classes | Objects |
| Example | A dog is an animal | A car has an engine |

## Polymorphism

It means different forms: a common behaviour with different implementations. A car, a bike and a person can all move, but each one moves in a different way.

It can be implemented through overloading and templates, which are resolved at compile time, or through virtual functions, which are resolved at runtime. It is used together with inheritance and composition.

> [!NOTE]
> All together they promote reuse, scalability and extensibility.

# Classes

A class is a blueprint, a set of instructions to build a specific type of object. It represents an abstraction, so it contains only the characteristics that are important.

Every object is built from the class through a process called instantiation, so every object is an instance of the class. A class can have multiple instances, and each one operates independently from the others.

syntax:

```cpp
class <name> {
<modifier>:
    <member variables>
    <member functions>
};
```

The access modifiers are:

- `private` → accessible only inside the class. It is the default if no modifier is set.
- `public` → accessible from outside.
- `protected` → like private, but also accessible from the child classes.

```cpp
class Car {
private:
    float fuel;
    float speed;
    int passengers;

public:
    void FillFuel(float amount);
    void Accelerate();
};

Car car;                // instantiation
car.Accelerate();       // fine, it is public
car.speed = 100;        // error, it is private
```

> [!WARNING]
> A class definition ends with `;` after the closing brace, unlike a function.

## Constructor

A special function that is invoked automatically when an instance is created. It is used to initialize the state of the object.

It has the same name as the class and no return type, but it can accept arguments and it can be overloaded.

```cpp
class Car {
private:
    float fuel;
    float speed;

public:
    Car() { fuel = 0; speed = 0; }                  // default constructor
    Car(float amount) { fuel = amount; speed = 0; } // parameterized constructor
};

Car c1;          // calls Car()
Car c2(50.0f);   // calls Car(float)
```

1. Default constructor → no arguments. The compiler creates one automatically if we do not write any constructor.

2. Parameterized constructor → one or more arguments. If we write one, the compiler no longer creates the default one, so `Car c;` stops compiling unless we write it too.

## Destructor

A special function invoked automatically when an object is destroyed. It is used to release the resources allocated in the constructor, like memory reserved with `new`.

Its name is the class name with `~`. It does not accept arguments, so it cannot be overloaded: there is only one per class.

```cpp
~Car() { }
```
## Structure

Another way of creating a user defined type, with the keyword `struct`. It is very similar to a class, the only difference is that the default access is public, while in a class it is private.

It is frequently used:

1. To represent simple abstract types, such as a point or a vector3D.
2. For implementing function objects, which are used as callbacks in the standard template library.

```cpp
struct Point {
    int x;
    int y;
};

void DrawLine(Point start, Point end) {
    std::cout << start.x << std::endl;
}
```

## Non-static data member initializers

Since C++11 we can initialize the member variables in the class declaration itself, so they always have a valid value without writing a constructor.

```cpp
class Car {
private:
    float fuel{0.0f};
    float speed{0.0f};
    int passengers{0};
};
```

If there is also a constructor that initializes the same member, the value of the constructor wins.

> [!NOTE]
> `auto` cannot be used with non-static data member initializers.

## This pointer

A member function is written once, but every object has its own attributes. When we call `a.Accelerate()`, the compiler passes the address of `a` to the function so it knows whose `speed` to increase. That hidden pointer is `this`.

Writing it is optional: when we write `speed`, the compiler already translates it to `this->speed`. So `speed++` is the normal way.

```cpp
void Car::Accelerate() {
    speed++;
    fuel -= 0.5f;
}
```

The arrow `->` is used because `this` is a pointer. It is the same as `(*this).speed`, only shorter.

It is only really needed when a parameter has the same name as a member. Without it the nearest name wins, which is the parameter, so the attribute is never changed.

```cpp
void Car::FillFuel(float fuel) {
    fuel = fuel;         // does nothing, the parameter assigns to itself
    this->fuel = fuel;   // the member takes the value of the parameter
}
```

## Constant member functions

They are qualified with the `const` keyword, which is required in both the declaration and the definition. A `const` function cannot change the value of any member variable, so it is useful for creating read-only functions.

```cpp
// in the class
void Dashboard() const;

// in the .cpp
void Car::Dashboard() const {
    std::cout << speed << std::endl;   // reading is fine
    speed = 0;                         // error, it cannot modify
}
```

The reason is that a `const` object can only call `const` functions.

```cpp
const Car car(4);
car.Dashboard();     // fine
car.Accelerate();    // error, Accelerate is not const
```

All the member functions that do not modify the state of the object should be qualified with `const`.

## Static class members

A normal member belongs to the object: every car has its own `speed`. A `static` member belongs to the class, so there is only one copy shared by all the objects.

### Static member variables

They cannot be initialized inside the class, they have to be defined outside, in the `.cpp` file.

```cpp
// car.h
class Car {
private:
    static int totalCars;
};

// car.cpp
int Car::totalCars = 0;   // definition, only once in the whole program
```

They are used for data that belongs to the type or class and not to any particular object, like counting how many instances have been created. The constructor increments it and the destructor decrements it.

Example: To count the number of object initialized for a certain class.


### Static member functions

They can be called without any object, using the class name.

```cpp
class Car {
public:
    static int GetTotalCars();
};

Car::GetTotalCars();   // no object needed
```

They have no `this` pointer, because they are not called on an object. That means they can only access static members, never the normal ones.


## Copy constructor

It creates a new object as a copy of an existing one, copying the values of the member variables.

syntax: `<name>(const <name> &other);`

```cpp
Integer i2(i1);   // copy constructor
Integer i3 = i1;  // the same
```

The parameter of the copy function must be a reference. It cannot be by value, because copying the argument would call the copy constructor again, forever.

If we do not define one, the compiler synthesizes it and copies the members one by one. This is a problem when the class has pointers: it copies the address, so both objects point to the same memory. That is a shallow copy.

```cpp
Integer::Integer(const Integer &other) {
    value = new int(*other.value);   // deep copy
}
```

> [!WARNING]
> With a shallow copy, when one object is destroyed the other is left with a dangling pointer.

## The rule of three

If a class allocates a resource in the constructor, we have to implement these three:

1. Destructor
2. Copy constructor
3. Copy assignment operator

If we implement one of them, we probably need the other two.

## Delegating constructors

Since C++11 a constructor can invoke another constructor of the same class. It is useful when there are several constructors: we write the common initialization code in one of them and the others delegate to it, so the code is not duplicated.

The call goes after the `:`, before the body.

```cpp
class Car {
private:
    float fuel;
    int passengers;

public:
    Car(float amount, int count) {   // the one with the real code
        fuel = amount;
        passengers = count;
    }

    Car() : Car(0.0f, 0) { }         // delegates to the one above
    Car(float amount) : Car(amount, 0) { }
};
```

> [!WARNING]
> A constructor cannot delegate to itself, and it cannot delegate to two constructors at the same time. Only one call is allowed.

## Default and delete specifiers

Both are written in the declaration, with `= default` or `= delete` instead of a body.

`= default` asks the compiler to synthesize the function. It only works with the functions the compiler can synthesize: constructor, destructor, copy constructor and copy assignment operator.

It is useful when we write a parameterized constructor, because that stops the compiler from creating the default one.

```cpp
class Car {
public:
    Car(float amount);
    Car() = default;     // we get the default constructor back
};
```

`= delete` tells the compiler not to synthesize the function, so calling it is a compile error. It is used when we do not want the objects of a class to be copied.

```cpp
class Car {
public:
    Car(const Car &other) = delete;              // cannot be copied
    Car& operator=(const Car &other) = delete;   // cannot be assigned
};

Car a(10.0f);
Car b(a);     // error
```

It also works with any other function, to forbid calling it with certain types. Without the deleted overload, `Print(3.14)` would convert the argument to `int` silently.

```cpp
void Print(int value);
void Print(double value) = delete;   // Print(3.14) is now an error
```

Unlike making them private, `= delete` gives a clear error at compile time and works everywhere, also inside the class.