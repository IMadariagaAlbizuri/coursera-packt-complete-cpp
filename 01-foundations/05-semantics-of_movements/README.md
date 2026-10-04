# Move semantics

## L-values and r-values

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