#include <iostream>
#include <stdexcept>
using namespace std;

// mexception33 class
class mexception33 : public exception 
{
    int code;
    string message;
public:
    mexception33(int c, const string& msg) : code(c), message(msg) {}
    int getCode() const { return code; }
    const char* what() const noexcept override 
    {
        return message.c_str();
    }
};

// Complex number class
class Complex 
{
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    Complex operator+(const Complex& o) const 
    {
        return Complex(real + o.real, imag + o.imag);
    }
    friend ostream& operator<<(ostream& os, const Complex& c) 
    {
        return os << "(" << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i)";
    }
};

// Rational number class
class Rational 
{
    int num, den;
    void reduce() 
    {
        int g = gcd(abs(num), abs(den));
        num /= g; 
        den /= g;
        if (den < 0) { num = -num; den = -den; }
    }
    int gcd(int a, int b) 
    {
        int gcd;
        for(int i=2;i<=a&&i<=b;i++)
        {
            if(a%i==0&&b%i==0)
            {
                gcd=i;
            }
        }
        return gcd;
    }
public:
    Rational(int n = 0, int d = 1) : num(n), den(d) 
    {
        if (d == 0) throw mexception33(1, "Denominator cannot be zero.");
        reduce();
    }
    Rational operator+(const Rational& o) const 
    {
        return Rational(num * o.den + o.num * den, den * o.den);
    }
    friend ostream& operator<<(ostream& os, const Rational& r) 
    {
        return os << r.num << "/" << r.den;
    }
};

// 3D vector class
class Vector3 
{
    double x, y, z;
public:
    Vector3(double X = 0, double Y = 0, double Z = 0) : x(X), y(Y), z(Z) {}
    Vector3 operator+(const Vector3& v) const 
    {
        return Vector3(x + v.x, y + v.y, z + v.z);
    }
    friend ostream& operator<<(ostream& os, const Vector3& v) 
    {
        return os << "[" << v.x << ", " << v.y << ", " << v.z << "]";
    }
};

// Matrix33 template
template<typename T>
class Matrix33 
{
protected:
    T data[3][3];
public:
    Matrix33() 
    {
        for (int i = 0; i < 3; ++i)
        { 
            for (int j = 0; j < 3; ++j)
            {
               data[i][j] = T();
            }
        }
    }
    T& at(int r, int c) 
    {
        if (r < 0 || r > 2 || c < 0 || c > 2)
            throw mexception33(2, "Index out of bounds.");
        return data[r][c];
    }
    Matrix33<T> operator+(const Matrix33<T>& other) const 
    {
        Matrix33<T> result;
        for (int i = 0; i < 3; ++i)
        { 
            for (int j = 0; j < 3; ++j)
            {
               result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    virtual void print() const 
    {
        for (int i = 0; i < 3; ++i) 
        {
            for (int j = 0; j < 3; ++j)
            {
                cout << data[i][j] << "\t";
            }
            cout << "\n";
        }
    }
};

// Null33 matrix
template<typename T>
class Null33 : public Matrix33<T> 
{
public:
    Null33() 
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                this->data[i][j] = T(); // default value
            }
        }
    }
};

// Identity33 matrix
template<typename T>
class Identity33 : public Matrix33<T> 
{
public:
    Identity33() 
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                this->data[i][j] = (i == j) ? T(1) : T();
            }
        }
    }
};

// Demonstration in main
int main() 
{
    try 
    {
        // Int matrix
        Matrix33<int> m1;
        m1.at(0, 0) = 1; m1.at(1, 1) = 2; m1.at(2, 2) = 3;
        cout << "Integer Matrix:\n"; 
        m1.print();

        // Float matrix
        Matrix33<float> m2;
        m2.at(0, 0) = 1.1f; m2.at(1, 1) = 2.2f; m2.at(2, 2) = 3.3f;
        cout << "\nFloat Matrix:\n"; 
        m2.print();

        // Complex matrix
        Matrix33<Complex> mc;
        mc.at(0, 0) = Complex(1, 2); mc.at(1, 1) = Complex(3, 4);
        cout << "\nComplex Matrix:\n"; 
        mc.print();

        // Rational matrix
        Matrix33<Rational> mr;
        mr.at(0, 0) = Rational(1, 2); mr.at(1, 1) = Rational(2, 3);
        cout << "\nRational Matrix:\n"; 
        mr.print();

        // Vector matrix
        Matrix33<Vector3> mv;
        mv.at(0, 0) = Vector3(1, 0, 0); mv.at(1, 1) = Vector3(0, 1, 0);
        mv.at(2, 2) = Vector3(0, 0, 1);
        cout << "\nVector3 Matrix:\n"; 
        mv.print();

        // Identity and Null
        Identity33<int> idInt;
        Null33<int> nullInt;
        cout << "\nIdentity Matrix<int>:\n"; 
        idInt.print();
        cout << "\nNull Matrix<int>:\n"; 
        nullInt.print();

        // Triggering exception
        Rational bad(1, 0); // will throw

    } 
    catch (const mexception33& e) 
    {
        cout << "Exception: " << e.what() << " [Code " << e.getCode() << "]"<<endl;
    }
    return 0;
}