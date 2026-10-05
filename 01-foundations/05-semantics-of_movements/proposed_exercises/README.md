# **Move Semantics Exercise**

Copy the folder of the Classes exercise into a new one. Add to `Measurements` the move constructor and the two assignment operators:

```cpp
    Measurements(Measurements &&other);                  // move constructor
    Measurements& operator=(const Measurements &other);  // copy assignment
    Measurements& operator=(Measurements &&other);       // move assignment
```

The five special functions (destructor, copy constructor and these three) print a message with their own name, so we can see which one is called.

+ Move constructor: takes the address of the array and leaves the source with `nullptr` and size 0. It creates a new object, so it also increments `totalObjects`.
+ Copy assignment: the object already exists, so it releases its own array first and then makes a deep copy. It returns `*this`.
+ Move assignment: releases its own array, takes the one of the source and leaves it empty. It returns `*this`.

In main():

+ Create `a`, copy it into `b` and move it into `c` with `std::move`. Print the three and check that `a` is empty.
+ Create `d` and assign to it `b`, and then `std::move(c)`. Read which message appears each time.
+ Write `void Consume(Measurements m){}` and call it with `b` and with `std::move(b)`.