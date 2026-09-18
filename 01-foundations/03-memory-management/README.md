# Memory management

C and C++ provide different types of memory areas, and all of them are taken from the process address space:

1º Stack → allocated automatically for local variables.
2º Data section → allocated for global and static data.
3º Heap → allocated at runtime.

The stack and the data section are managed by the runtime. The heap is the one that has to be managed by the programmer, and that is what dynamic memory means: memory allocated while the program is running.

## Dynamic memory in C

```cpp
#include <cstdio>
#include <cstdlib>

int main() {
    int *p = (int*)malloc(sizeof(int));

    if (p == NULL) {
        printf("Failed to allocate memory\n");
        return -1;
    }

    *p = 5;
    printf("%d", *p);

    free(p);
    p = NULL;
    return 0;
}
```

The functions to work with the heap:

- `malloc` → allocates raw memory, without initializing it.
- `calloc` → allocates memory and initializes it to zero.
- `realloc` → allocates a larger chunk for an existing allocation.
- `free` → releases the memory allocated by the functions above.

They return `NULL` when they cannot allocate the memory, so the result must always be checked before using it.

In C++ the cast is mandatory, because these functions return a `void*` and it does not convert automatically: `int *p = (int*)calloc(1, sizeof(int));`

> [!WARNING]
> After freeing a pointer, always assign `NULL` to it. The memory is gone but the pointer still holds the old address, and that is a dangling pointer.

> [!WARNING]
> If we forget to call `free`, we lose the address and the memory can never be released. This is a memory leak, and it is a serious problem because the process keeps growing.

The memory must be freed manually by the programmer. C++ has its own operators, `new` and `delete`, which are the ones we normally use.

## Dynamic memory in C++

C++ provides two operators for dynamic memory: `new` allocates on the heap, and `delete` releases it. Memory allocated with `new` has to be released with `delete`.

syntax: `<type> *<name> = new <type>(<optional args>);`

```cpp
int *p = new int(5);   // allocates and initializes
delete p;
p = nullptr;
```

For arrays there is a second form, and it has its own `delete`:

```cpp
int *arr = new int[10];
delete[] arr;
```

Mixing them is undefined behaviour: memory from `new[]` must be released with `delete[]`, never with `delete`.

When `new` cannot allocate the memory it throws an exception, so there is no `NULL` to check like in C.

## Difference between malloc and new

| | malloc | new |
|---|---|---|
| What it is | A function | An operator |
| Size | Has to be given | Taken from the type |
| Initialization | Cannot initialize | Can initialize |
| Constructors | Cannot call them | Calls them |
| Return type | `void*`, needs a cast | The correct type |
| Customization | Cannot be customized | Can be overloaded |
| Forms | malloc, calloc, realloc | Has different forms |
| On failure | Returns `NULL` | Throws an exception |

This is why in C++ we use `new` and `delete`, not `malloc` and `free`.

# Arrays in the heap

To allocate an array on the heap we need another form of the operators, `new[]` and `delete[]`.

syntax: `<type> *<name> = new <type>[<size>];`

```cpp
int *p = new int[5];     // uninitialized
int *q = new int[5]{};   // every element is 0
delete[] p;
p = nullptr;
```

The size does not have to be known at compile time, which is the advantage over a normal array.

```cpp
int size;
std::cin >> size;
int *data = new int[size];
```

The elements are accessed as always, with `data[i]` or `*(data + i)`.

> [!WARNING]
> Memory from `new[]` must be released with `delete[]`, never with `delete`. Mixing them is undefined behaviour.

> [!NOTE]
> For strings we always have to allocate an extra byte for the null terminating character `'\0'`.

# 2D arrays in the heap

A normal 2D array is contiguous in memory, and the compiler lets us use the row-column syntax.

```cpp
int data[2][3]{1, 2, 3, 4, 5, 6};
data[0][1];
```

In the heap it is different: we need an array of pointers, where each one points to a row.

```cpp
int **pData = new int*[2];   // 1D array of 2 pointers

pData[0] = new int[3];       // each pointer gets its own row
pData[1] = new int[3];

pData[0][1] = 2;             // second element of the first row

delete[] pData[0];           // first the rows
delete[] pData[1];
delete[] pData;              // then the array of pointers

pData = nullptr;
```

The `int**` is a pointer to a pointer: it holds the address of the first pointer of the array.

The order of the deletes matters. If we free `pData` first, we lose the addresses of the rows and they can never be released.

> [!WARNING]
> The number of `delete` calls must match the number of `new` calls. Here there are three of each.

Unlike a normal 2D array, the rows are not contiguous in memory: each one is a separate allocation that can be anywhere in the heap.