#ifndef point3d_h
#define point3d_h

#include <iostream>
#include <cmath>

class Point3D {
private:
    double x, y, z;

public:
    // Constructors
    Point3D();
    Point3D(double x, double y, double z);
    Point3D(const Point3D& other);

    // Getters
    double getX() const;
    double getY() const;
    double getZ() const;

    // Setters
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    void setXYZ(double x, double y, double z);

    // Operator Overloads
    bool operator==(const Point3D& other) const;
    bool operator!=(const Point3D& other) const;
    Point3D operator+(const Point3D& other) const;
    Point3D operator-(const Point3D& other) const;
    Point3D operator*(double scalar) const;
    Point3D operator/(double scalar) const;

    // Distance Calculation
    double distanceTo(const Point3D& other) const;

    // Display function
    void print() const;
};

#endif