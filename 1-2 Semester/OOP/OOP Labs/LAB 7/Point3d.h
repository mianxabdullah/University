#ifndef POINT3D_H
#define POINT3D_H

#include <iostream>
#include <string>

using namespace std;

class Point3d
{
protected:
    float x, y, z;
public:
    Point3d();
    float getX() const;
    float getY() const;
    float getZ() const;
    Point3d(float, float, float);
    void displace(float, float, float);
    float distance(const Point3d &) const;
    bool operator==(const Point3d &) const;
    bool operator!=(const Point3d &) const;
    Point3d operator*(float) const;
    friend Point3d operator*(float, const Point3d &);
    Point3d operator/(float) const;
    friend ostream & operator<<(ostream & strm, const Point3d &);
    friend istream & operator>>(istream & strm, Point3d &);
};
 
#endif

