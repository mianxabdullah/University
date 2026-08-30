/*
Considering a class Polynomial as discussed in the class sessions. Assuming
the variable is fixed as x, let the class have only one data member for
coefficients, a list of numbers with length 1 more than degree of the
Polynomial object. Write definition/code for its following members:
To get/set the coefficients of polynomial through [] index.
To verify a polynomial is bigger than other polynomial w.r.t., to their degrees.
To return derivative of a polynomial
To return the sum of two polynomials
To return the product of two polynomials

*/


#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <cmath>

using namespace std;

class Polynomial {
private:
    double* coeffs;
    int capacity;

    void resize(int new_capacity) {
        double* new_coeffs = new double[new_capacity];
        int copy_size = min(capacity, new_capacity);
        for (int i = 0; i < copy_size; i++) {
            new_coeffs[i] = coeffs[i];
        }
        delete[] coeffs;
        coeffs = new_coeffs;
        capacity = new_capacity;
    }

public:
	
    int degree() const 
	{
        for (int i = capacity - 1; i >= 0; i--) 
		{
            if (coeffs[i] != 0) return i;
        }
        return 0;
    }
	
    Polynomial(int degree = 0) : capacity(degree + 1) {
        coeffs = new double[capacity]{0};
    }
    
    Polynomial(const Polynomial& other) : capacity(other.capacity) {
        coeffs = new double[capacity];
        for (int i = 0; i < capacity; i++) {
            coeffs[i] = other.coeffs[i];
        }
    }
    
    ~Polynomial() { delete[] coeffs; }
    
    Polynomial& operator=(const Polynomial& other) {
        if (this != &other) {
            delete[] coeffs;
            capacity = other.capacity;
            coeffs = new double[capacity];
            for (int i = 0; i < capacity; i++) {
                coeffs[i] = other.coeffs[i];
            }
        }
        return *this;
    }

    double& operator[](int index) {
        if (index < 0) throw out_of_range("Negative index");
        if (index >= capacity) resize(index + 1);
        return coeffs[index];
    }
    
    const double& operator[](int index) const {
        if (index < 0 || index >= capacity) throw out_of_range("Index out of bounds");
        return coeffs[index];
    }

    bool operator>(const Polynomial& other) const {
        return degree() > other.degree();
    }



    Polynomial derivative() const 
	{
        if (capacity == 1) return Polynomial();
        
        Polynomial result(capacity - 2);
        for (int i = 1; i < capacity; i++) {
            result[i-1] = coeffs[i] * i;
        }
        return result;
    }

    Polynomial operator+(const Polynomial& other) const {
        int maxDegree = max(degree(), other.degree());
        Polynomial result(maxDegree);
        
        for (int i = 0; i <= maxDegree; i++) {
            double a = (i < capacity) ? coeffs[i] : 0;
            double b = (i < other.capacity) ? other.coeffs[i] : 0;
            result[i] = a + b;
        }
        return result;
    }

    Polynomial operator*(const Polynomial& other) const {
        int resultDegree = degree() + other.degree();
        Polynomial result(resultDegree);
        
        for (int i = 0; i < capacity; i++) {
            if (coeffs[i] == 0) continue;
            for (int j = 0; j < other.capacity; j++) {
                result[i+j] += coeffs[i] * other.coeffs[j];
            }
        }
        return result;
    }

    void display() const {
        bool firstTerm = true;
        for (int i = degree(); i >= 0; i--) {
            if (coeffs[i] == 0) continue;

            if (!firstTerm) {
                cout << (coeffs[i] > 0 ? " + " : " - ");
            } else if (coeffs[i] < 0) {
                cout << "-";
            }

            double abs_coeff = abs(coeffs[i]);
            if (abs_coeff != 1 || i == 0) {
                cout << abs_coeff;
            }

            if (i > 0) {
                cout << "x";
                if (i > 1) {
                    cout << "^" << i;
                }
            }
            firstTerm = false;
        }
        if (firstTerm) cout << "0";
        cout << endl;
    }
};

int main() {
    Polynomial p1(2);
    p1[0] = 3;
    p1[1] = 2;
    p1[2] = 1;
    
    Polynomial p2(3);
    p2[0] = 1;
    p2[1] = -1;
    p2[3] = 2;

    cout << "Polynomial p1: ";
    p1.display();
    
    cout << "Polynomial p2: ";
    p2.display();

    cout << "\nSetting p1[1] = 5\n";
    p1[1] = 5;
    cout << "Modified p1: ";
    p1.display();

    cout << "\nDegree comparison:\n";
    cout << "p2 > p1? " << (p2 > p1 ? "Yes" : "No") << endl;

    cout << "\nDerivative of p1: ";
    Polynomial p1_deriv = p1.derivative();
    p1_deriv.display();

    cout << "\nSum p1 + p2: ";
    Polynomial sum = p1 + p2;
    sum.display();

    cout << "\nProduct p1 * p2: ";
    Polynomial product = p1 * p2;
    product.display();

    Polynomial zero;
    cout << "\nZero polynomial: ";
    zero.display();
    
    cout << "Derivative of zero polynomial: ";
    zero.derivative().display();

    return 0;
}