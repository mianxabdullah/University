#include <iostream>
#include <cmath> // Only for sqrt(), can be implemented manually if needed

class Vector4d {
private:
    double x, y, z, w;

public:
    // Constructor
    Vector4d(double x = 0, double y = 0, double z = 0, double w = 0) 
        : x(x), y(y), z(z), w(w) {}

    // Magnitude of the vector
    double magnitude() const {
        return sqrt(x*x + y*y + z*z + w*w);
    }

    // Check if unit vector
    bool isUnitVector() const {
        double mag = magnitude();
        // Compare with tolerance for floating point numbers
        return (mag > 0.9999 && mag < 1.0001);
    }

    // Dot product with another vector
    double dotProduct(const Vector4d& other) const {
        return x*other.x + y*other.y + z*other.z + w*other.w;
    }

    // Difference between two vectors (operator overloading)
    Vector4d operator-(const Vector4d& other) const {
        return Vector4d(x - other.x, y - other.y, z - other.z, w - other.w);
    }

    // Additive inverse (negation operator overloading)
    Vector4d operator-() const {
        return Vector4d(-x, -y, -z, -w);
    }

    // Display the vector (for demonstration)
    void display() const {
        std::cout << "(" << x << ", " << y << ", " << z << ", " << w << ")";
    }
};

int main() {
    // Demonstration
    Vector4d v1(1, 0, 0, 0);
    Vector4d v2(0, 1, 0, 0);
    Vector4d v3 = v1 - v2;
    Vector4d v4 = -v1;

    std::cout << "v1: "; v1.display(); std::cout << std::endl;
    std::cout << "Magnitude of v1: " << v1.magnitude() << std::endl;
    std::cout << "Is v1 a unit vector? " << (v1.isUnitVector() ? "Yes" : "No") << std::endl;
    std::cout << "Dot product v1·v2: " << v1.dotProduct(v2) << std::endl;
    std::cout << "v1 - v2: "; v3.display(); std::cout << std::endl;
    std::cout << "Additive inverse of v1: "; v4.display(); std::cout << std::endl;

    return 0;
}