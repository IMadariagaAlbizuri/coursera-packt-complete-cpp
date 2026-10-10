#include <iostream>
#include "Vector3D.h"
struct Point3D {
    double x, y, z;
    Point3D(const Vector3D &v) : x(v.GetX()), y(v.GetY()), z(v.GetZ()) {}
};

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