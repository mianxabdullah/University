#include"myint.h"

    MyInt::MyInt() 
    {
        val = new int(0);
    }

    MyInt::MyInt(int value = 0) {
        val = new int(value);
    }

    // Copy Constructor (deep copy)
    MyInt::MyInt(const MyInt& other) {
        val = new int(*(other.val));
    }

    // Move Constructor
    MyInt::MyInt(MyInt&& other) noexcept {
        val = other.val;   // steal the pointer
        other.val = nullptr; // leave other in safe state
    }

    // Destructor
    MyInt::~MyInt() {
        delete val;
    }

    // Copy Assignment (deep copy)
    MyInt& MyInt::operator=(const MyInt& other) 
    {
        if (this != &other) {
            delete val;
            val = new int(*(other.val));
        }
        return *this;
    }

    // Move Assignment
    MyInt& MyInt::operator=(MyInt&& other) noexcept 
    {
        if (this != &other) {
            delete val;        // free old memory
            val = other.val;   // steal pointer
            other.val = nullptr;
        }
        return *this;
    }

    // Getter
    int MyInt::getValue() const 
    {
        return *val;
    }

    // Setter
    void MyInt::setValue(int value) 
    {
        *val = value;
    }
