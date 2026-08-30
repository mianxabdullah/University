#include "Point3D.h"

int main() {
    Point3D p1(1.5, 2.0, 3.0);
    Point3D p2(4.0, 5.0, 6.0);
    
    std::cout << "Point 1: ";
    p1.print();
    std::cout << "\nPoint 2: ";
    p2.print();
    
    std::cout << "\n\nAddition: ";
    (p1 + p2).print();
    
    std::cout << "\nSubtraction: ";
    (p1 - p2).print();

    std::cout << "\nDistance between points: " << p1.distanceTo(p2) << "\n";

    return 0;
}