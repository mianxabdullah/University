#ifndef LINE3D_H
#define LINE3D_H

#include "Point3D.h"

class Line3D {
private:
    Point3D P1, P2;

public:
    // Constructors
    Line3D();
    Line3D(const Point3D& p1, const Point3D& p2);
    Line3D(const Line3D& other);

    // Getters
    Point3D getP1() const;
    Point3D getP2() const;

    // Setters
    void setP1(const Point3D& p1);
    void setP2(const Point3D& p2);
    void setPoints(const Point3D& p1, const Point3D& p2);

    // Operator Overloading
    bool operator==(const Line3D& other) const;
    bool operator!=(const Line3D& other) const;

    // Line Operations
    double length() const;
    bool isParallelTo(const Line3D& other) const;
    bool isPerpendicularTo(const Line3D& other) const;
    bool isCollinearWith(const Line3D& other) const;
    Point3D intersectionWith(const Line3D& other) const;
    bool isHorizontal() const;
    bool isVertical() const;
    double distanceToPoint(const Point3D& point) const;
    
    // Display function
    void print() const;
};

#endif