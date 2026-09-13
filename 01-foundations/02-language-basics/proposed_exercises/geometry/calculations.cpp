// The definitions of functions for geometry calculations 

#include <math.h>

float calculateCircleArea(float radius) {
    return 3.14159f * radius * radius;
};

float calculateCirclePerimeter(float radius) {
    return 2 * 3.14159f * radius;
};

float calculateRectangleArea(float length, float width) {
    return length * width;
};

float calculateRectanglePerimeter(float length, float width) {
    return 2 * (length + width);
};

float calculateTriangleArea(float base, float height) {
    return 0.5f * base * height;
};

float calculateTrianglePerimeter(float side1, float side2, float side3) {
    return side1 + side2 + side3;
};
