# Ejercicio: clase `Vector3D`

Crea una clase `Vector3D` con tres componentes `double`: `m_x`, `m_y` y `m_z`.

## Requisitos

1. **Constructor** `Vector3D(double x = 0, double y = 0, double z = 0)` con *member initializer list*.
2. **Getters** `GetX() const`, `GetY() const` y `GetZ() const`.
3. **`operator+` y `operator-` como miembros** (`Vector3D` con `Vector3D`), ambos `const`.
4. **`operator-` unario** como miembro: devuelve el vector opuesto.
5. **`operator*` como miembro**: `v * 2.0` (producto por escalar).
6. **`operator*` global**: `2.0 * v`. Reutiliza el miembro para no duplicar código.
7. **`operator+=` como miembro**: modifica el objeto y devuelve `Vector3D&`.
8. **`operator==` global**: compara las tres componentes.
9. **`operator[]`**: `v[0]` es x, `v[1]` es y y `v[2]` es z. Haz dos versiones: una `const` y otra no `const` que devuelve referencia.
10. **`operator<<` y `operator>>` globales**, con formato `(1, 2, 3)`. Si accedes a datos privados, usa `friend`.
11. **Conversión a primitivo**: `explicit operator double() const` que devuelva el módulo (la norma).
12. **Conversión a otro tipo tuyo**: una clase `Point3D` con un constructor `Point3D(const Vector3D &)`.

## `main` para probar

```cpp
int main() {
    Vector3D a{1, 2, 3}, b{2, 3, 6};

    std::cout << a + b << std::endl;      // (3, 5, 9)
    std::cout << b - a << std::endl;      // (1, 1, 3)
    std::cout << -a << std::endl;         // (-1, -2, -3)
    std::cout << a * 3.0 << std::endl;    // (3, 6, 9)
    std::cout << 3.0 * a << std::endl;    // (3, 6, 9)

    a += b;
    std::cout << a << std::endl;          // (3, 5, 9)

    std::cout << a[0] << " " << a[1] << " " << a[2] << std::endl;   // 3 5 9
    a[2] = 10;                            // usa la versión no const

    std::cout << (a == b) << std::endl;   // 0

    double norm = static_cast<double>(b); // 7
    std::cout << norm << std::endl;

    Point3D p = b;                        // conversión Vector3D -> Point3D
    return 0;
}
```