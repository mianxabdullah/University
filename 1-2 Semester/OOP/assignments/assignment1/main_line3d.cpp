#include "Line3D.h"

int main() {
    Point3D a(1, 2, 3);
    Point3D b(4, 5, 6);
    Line3D line1(a, b);

    std::cout << "Line 1: ";
    line1.print();
    std::cout << "\nLength: " << line1.length();

    Point3D c(2, 3, 4);
    Point3D d(5, 6, 7);
    Line3D line2(c, d);

    std::cout << "\n\nLine 2: ";
    line2.print();
    
    std::cout << "\nAre lines parallel? " << (line1.isParallelTo(line2) ? "Yes" : "No");
    std::cout << "\nAre lines perpendicular? " << (line1.isPerpendicularTo(line2) ? "Yes" : "No");

    std::cout << "\n\nDistance from point (0,0,0) to Line 1: " << line1.distanceToPoint(Point3D(0,0,0)) << "\n";

    return 0;
}