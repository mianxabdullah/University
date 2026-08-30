#include <iostream>
#include <cmath>

class NDVector 
{
private:
    double* components;
    int dim;
    
public:
    // Constructor
    NDVector(double* comps, int dimension) : dim(dimension) {
        components = new double[dim];
        for (int i = 0; i < dim; i++) {
            components[i] = comps[i];
        }
    }
    
    // Destructor
    ~NDVector() {
        delete[] components;
    }
    
    // Copy constructor
    NDVector(const NDVector& other) : dim(other.dim) {
        components = new double[dim];
        for (int i = 0; i < dim; i++) {
            components[i] = other.components[i];
        }
    }
    
    // Get dimension
    int dimension() const {
        return dim;
    }
    
    // Get component at index
    double get(int index) const {
        if (index < 0 || index >= dim) {
            std::cout << "Error: Index out of bounds\n";
            return 0.0;
        }
        return components[index];
    }
    
    // Magnitude (norm) of the vector
    double magnitude() const {
        double sum = 0.0;
        for (int i = 0; i < dim; i++) {
            sum += components[i] * components[i];
        }
        return sqrt(sum);
    }
    
    // Dot product with another vector
    double dot(const NDVector& other) const {
        if (dim != other.dim) {
            std::cout << "Error: Vectors must have the same dimension\n";
            return 0.0;
        }
        
        double result = 0.0;
        for (int i = 0; i < dim; i++) {
            result += components[i] * other.components[i];
        }
        return result;
    }
    
    // Print vector
    void print() const {
        std::cout << "(";
        for (int i = 0; i < dim; i++) {
            if (i != 0) std::cout << ", ";
            std::cout << components[i];
        }
        std::cout << ")";
    }
};

int main() {
    // Test 1D vector (just a number)
    double v1_data[] = {5.0};
    double v2_data[] = {-3.0};
    NDVector v1(v1_data, 1);
    NDVector v2(v2_data, 1);
    
    std::cout << "1D Vector Tests:\n";
    std::cout << "v1: "; v1.print(); std::cout << "\n";
    std::cout << "v2: "; v2.print(); std::cout << "\n";
    std::cout << "Magnitude v1: " << v1.magnitude() << " (expected: 5)\n";
    std::cout << "Dot product: " << v1.dot(v2) << " (expected: -15)\n\n";
    
    // Test 2D vector
    double v3_data[] = {3.0, 4.0};
    double v4_data[] = {1.0, -2.0};
    NDVector v3(v3_data, 2);
    NDVector v4(v4_data, 2);
    
    std::cout << "2D Vector Tests:\n";
    std::cout << "v3: "; v3.print(); std::cout << "\n";
    std::cout << "v4: "; v4.print(); std::cout << "\n";
    std::cout << "Magnitude v3: " << v3.magnitude() << " (expected: 5)\n";
    std::cout << "Dot product: " << v3.dot(v4) << " (expected: -5)\n\n";
    
    // Test 3D vector
    double v5_data[] = {1.0, 2.0, 2.0};
    double v6_data[] = {3.0, 4.0, 0.0};
    NDVector v5(v5_data, 3);
    NDVector v6(v6_data, 3);
    
    std::cout << "3D Vector Tests:\n";
    std::cout << "v5: "; v5.print(); std::cout << "\n";
    std::cout << "v6: "; v6.print(); std::cout << "\n";
    std::cout << "Magnitude v5: " << v5.magnitude() << " (expected: 3)\n";
    std::cout << "Dot product: " << v5.dot(v6) << " (expected: 11)\n\n";
    
    // Test dimension mismatch
    std::cout << "Testing dimension mismatch:\n";
    std::cout << "Dot product of v1 (1D) and v3 (2D): " << v1.dot(v3) << "\n";
    
    return 0;
}