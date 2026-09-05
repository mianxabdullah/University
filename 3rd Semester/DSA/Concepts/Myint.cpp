#include <iostream>
using namespace std;

class MyInt //OOP concepts and BIG-5 
{
private:
    int* val;  // pointer to an integer

public:
    // Constructor
    MyInt(int value = 0) {
        val = new int(value);
    }

    // Copy Constructor (deep copy)
    MyInt(const MyInt& other) {
        val = new int(*(other.val));
    }

    // Move Constructor
    MyInt(MyInt&& other) noexcept {
        val = other.val;   // steal the pointer
        other.val = nullptr; // leave other in safe state
    }

    // Destructor
    ~MyInt() {
        delete val;
    }

    // Copy Assignment (deep copy)
    MyInt& operator=(const MyInt& other) {
        if (this != &other) {
            delete val;
            val = new int(*(other.val));
        }
        return *this;
    }

    // Move Assignment
    MyInt& operator=(MyInt&& other) noexcept {
        if (this != &other) {
            delete val;        // free old memory
            val = other.val;   // steal pointer
            other.val = nullptr;
        }
        return *this;
    }

    // Getter
    int getValue() const {
        return *val;
    }

    // Setter
    void setValue(int value) {
        *val = value;
    }
};
int main() {
    MyInt a(10);
    MyInt b = a;          // copy constructor
    MyInt c = MyInt(20);  // move constructor
    MyInt d;
    d = a;                // copy assignment
    MyInt e;
    e = MyInt(30);        // move assignment

    cout << "a = " << a.getValue() << endl;
    cout << "b = " << b.getValue() << endl;
    cout << "c = " << c.getValue() << endl;
    cout << "d = " << d.getValue() << endl;
    cout << "e = " << e.getValue() << endl;

    return 0;
}