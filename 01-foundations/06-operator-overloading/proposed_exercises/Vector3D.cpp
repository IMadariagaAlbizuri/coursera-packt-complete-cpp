#include "Vector3D.h"
#include <cmath>

Vector3D::Vector3D(): Vector3D(0,0,0){}

Vector3D::Vector3D(double x, double y, double z){
    m_Vector = new double[3];
    m_Vector[0]=x;
    m_Vector[1]=y;
    m_Vector[2]=z;
}

Vector3D::Vector3D(const Vector3D &other){
    this->m_Vector=new double[3];
    this->m_Vector[0]=other.GetX();
    this->m_Vector[1]=other.GetY();
    this->m_Vector[2]=other.GetZ();
}

Vector3D::Vector3D(Vector3D &&other) noexcept{
    this->m_Vector = other.m_Vector;
    other.m_Vector=nullptr;
}

Vector3D::~Vector3D(){
    delete[] m_Vector;
}

Vector3D &Vector3D::operator=(const Vector3D &other){
    if (this != &other) {
        if (m_Vector == nullptr)
            m_Vector = new double[3];
        m_Vector[0] = other.m_Vector[0];
        m_Vector[1] = other.m_Vector[1];
        m_Vector[2] = other.m_Vector[2];
    }
    return *this;
}

Vector3D &Vector3D::operator=(Vector3D &&other) noexcept{
    if (this != &other) {
        delete[] m_Vector;
        m_Vector = other.m_Vector;
        other.m_Vector = nullptr;
    }
    return *this;
}

double Vector3D::GetX() const{
    return m_Vector[0];
}

double Vector3D::GetY() const{
    return m_Vector[1];
}

double Vector3D::GetZ() const{
    return m_Vector[2];
}

const double *Vector3D::GetVector() const{
    return m_Vector;
}

void Vector3D::SetX(double x){
    m_Vector[0]=x;
}

void Vector3D::SetY(double y){
    m_Vector[1]=y;
}

void Vector3D::SetZ(double z){
    m_Vector[2]=z;
}

void Vector3D::SetVector(double x, double y, double z){
    m_Vector[0]=x;
    m_Vector[1]=y;
    m_Vector[2]=z;
}

Vector3D Vector3D::operator+(const Vector3D &other) const{
    return Vector3D(GetX()+other.GetX(),GetY()+other.GetY(),GetZ()+other.GetZ());
}

Vector3D Vector3D::operator-(const Vector3D &other) const{
    return Vector3D(GetX()-other.GetX(),GetY()-other.GetY(),GetZ()-other.GetZ());
}

Vector3D Vector3D::operator-() const{
    return Vector3D(-GetX(), -GetY(), -GetZ());
}

Vector3D &Vector3D::operator+=(const Vector3D &other){
    m_Vector[0] += other.m_Vector[0];
    m_Vector[1] += other.m_Vector[1];
    m_Vector[2] += other.m_Vector[2];
    return *this;
}

double &Vector3D::operator[](int i){
    return m_Vector[i];
}

const double &Vector3D::operator[](int i) const{
    return m_Vector[i];
}

Vector3D::operator double() const{
    return Norm();
}

double Vector3D::Norm() const{
    return std::sqrt(GetX()*GetX()+GetY()*GetY()+GetZ()*GetZ());
}

Vector3D operator*(const Vector3D &v, double s){
    return Vector3D(v.GetX()*s, v.GetY()*s, v.GetZ()*s);
}

Vector3D operator*(double s, const Vector3D &v){
    return v * s;
}

bool operator==(const Vector3D &a, const Vector3D &b){
    return a[0]==b[0] && a[1]==b[1] && a[2]==b[2];
}

std::ostream &operator<<(std::ostream &out, const Vector3D &obj){
    out << "(" << obj.GetX() << ", " << obj.GetY() << ", " << obj.GetZ() << ")";
    return out;
}

std::istream &operator>>(std::istream &in, Vector3D &obj){
    double x, y, z;
    in >> x >> y >> z;
    if (in) {
        obj.SetVector(x, y, z);
    }
    return in;
}