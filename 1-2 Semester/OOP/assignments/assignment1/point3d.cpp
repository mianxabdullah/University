#include "Point3D.h"

// Default Constructor
Point3D::Point3D() : x(0), y(0), z(0) {}

// Parameterized Constructor
Point3D::Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

// Copy Constructor
Point3D::Point3D(const Point3D& other) : x(other.x), y(other.y), z(other.z) {}

// Getters
double Point3D::getX() const { return x; }
double Point3D::getY() const { return y; }
double Point3D::getZ() const { return z; }

// Setters
void Point3D::setX(double x) { this->x = x; }
void Point3D::setY(double y) { this->y = y; }
void Point3D::setZ(double z) { this->z = z; }
void Point3D::setXYZ(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

// Operator Overloading
bool Point3D::operator==(const Point3D& other) const {
    return (x == other.x && y == other.y && z == other.z);
}

bool Point3D::operator!=(const Point3D& other) const {
    return !(*this == other);
}

Point3D Point3D::operator+(const Point3D& other) const {
    return Point3D(x + other.x, y + other.y, z + other.z);
}

Point3D Point3D::operator-(const Point3D& other) const {
    return Point3D(x - other.x, y - other.y, z - other.z);
}

Point3D Point3D::operator*(double scalar) const {
    return Point3D(x * scalar, y * scalar, z * scalar);
}

Point3D Point3D::operator/(double scalar) const {
    if (scalar == 0) throw std::runtime_error("Division by zero");
    return Point3D(x / scalar, y / scalar, z / scalar);
}

// Distance Calculation
double Point3D::distanceTo(const Point3D& other) const {
    return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2) + pow(other.z - z, 2));
}

// Display function
void Point3D::print() const {
    std::cout << "(" << x << ", " << y << ", " << z << ")";
}