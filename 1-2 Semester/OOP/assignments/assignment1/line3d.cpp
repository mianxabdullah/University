#include "Line3D.h"

// Default Constructor
Line3D::Line3D() : P1(Point3D()), P2(Point3D(1, 1, 1)) {}

// Parameterized Constructor
Line3D::Line3D(const Point3D& p1, const Point3D& p2) : P1(p1), P2(p2) {}

// Copy Constructor
Line3D::Line3D(const Line3D& other) : P1(other.P1), P2(other.P2) {}

// Getters
Point3D Line3D::getP1() const { return P1; }
Point3D Line3D::getP2() const { return P2; }

// Setters
void Line3D::setP1(const Point3D& p1) { P1 = p1; }
void Line3D::setP2(const Point3D& p2) { P2 = p2; }
void Line3D::setPoints(const Point3D& p1, const Point3D& p2) {
    P1 = p1;
    P2 = p2;
}

// Operator Overloading
bool Line3D::operator==(const Line3D& other) const {
    return (P1 == other.P1 && P2 == other.P2) || (P1 == other.P2 && P2 == other.P1);
}

bool Line3D::operator!=(const Line3D& other) const {
    return !(*this == other);
}

// Compute the length of the line
double Line3D::length() const {
    return P1.distanceTo(P2);
}

// Check if two lines are parallel
bool Line3D::isParallelTo(const Line3D& other) const { 
    Point3D v1 = P2 - P1;
    Point3D v2 = other.P2 - other.P1;
    return (v1.getX() * v2.getY() == v1.getY() * v2.getX()) &&
           (v1.getX() * v2.getZ() == v1.getZ() * v2.getX());
}

// Check if two lines are perpendicular
bool Line3D::isPerpendicularTo(const Line3D& other) const {
    Point3D v1 = P2 - P1;
    Point3D v2 = other.P2 - other.P1;
    return (v1.getX() * v2.getX() + v1.getY() * v2.getY() + v1.getZ() * v2.getZ()) == 0;
}

// Check if two lines are collinear
bool Line3D::isCollinearWith(const Line3D& other) const {
    return isParallelTo(other) && P1.distanceTo(other.P1) == 0;
}

// Compute intersection point of two lines (assumes they are not parallel)
Point3D Line3D::intersectionWith(const Line3D& other) const {
    // Placeholder implementation - requires parametric equation solution
    throw std::runtime_error("Intersection computation is complex; needs more implementation.");
}

// Check if the line is horizontal
bool Line3D::isHorizontal() const {
    return P1.getZ() == P2.getZ();
}

// Check if the line is vertical
bool Line3D::isVertical() const {
    return P1.getX() == P2.getX() && P1.getY() == P2.getY();
}

// Compute distance from a point to the line
double Line3D::distanceToPoint(const Point3D& point) const {
    // Vector projection method
    Point3D AP = point - P1;
    Point3D AB = P2 - P1;
    double t = (AP.getX() * AB.getX() + AP.getY() * AB.getY() + AP.getZ() * AB.getZ()) / 
               (AB.getX() * AB.getX() + AB.getY() * AB.getY() + AB.getZ() * AB.getZ());
    
    Point3D closestPoint = P1 + AB * t;
    return point.distanceTo(closestPoint);
}

// Display function
void Line3D::print() const {
    std::cout << "Line from ";
    P1.print();
    std::cout << " to ";
    P2.print();
}