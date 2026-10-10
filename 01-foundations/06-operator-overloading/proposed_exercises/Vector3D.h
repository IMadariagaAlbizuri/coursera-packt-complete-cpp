#pragma once
#include <iostream>

class Vector3D{

private:

    double *m_Vector;

public:

    // Constructors
    Vector3D();
    Vector3D(double x, double y, double z);
    Vector3D(const Vector3D &other);              // Copy constructor
    Vector3D(Vector3D &&other) noexcept;          // Move constructor
    // Destructor
    ~Vector3D();
    // The copy and move assignments
    Vector3D& operator=(const Vector3D &other);       // Copy assignment operator
    Vector3D& operator=(Vector3D &&other) noexcept;   // Move assignment operator

    // Getters and Setters
    double GetX() const;
    double GetY() const;
    double GetZ() const;
    const double* GetVector() const;
    void SetX(double x);
    void SetY(double y);
    void SetZ(double z);
    void SetVector(double x, double y, double z);

    // Operators
    Vector3D operator+(const Vector3D &other) const;
    Vector3D operator-(const Vector3D &other) const;
    Vector3D operator-() const;
    Vector3D& operator+=(const Vector3D &other);
    double& operator[](int i);                        
    const double& operator[](int i) const;          

    friend Vector3D operator*(const Vector3D &v, double s);   // v * 2.0
    friend Vector3D operator*(double s, const Vector3D &v);   // 2.0 * v
    friend bool operator==(const Vector3D &a, const Vector3D &b);
    friend std::ostream& operator<<(std::ostream &out, const Vector3D &obj);
    friend std::istream& operator>>(std::istream &in, Vector3D &obj);

    explicit operator double() const;
    double Vector3D::Norm() const;
};