#ifndef MYINT_H
#define MYINT_H

#include <iostream>
using namespace std;

class MyInt //OOP concepts and BIG-5 
{
private:
    int* val;  // pointer to an integer

public:
    // Constructor
    MyInt();
    MyInt(int  ) ;
    MyInt(const MyInt& other) ;
    MyInt(MyInt&& other) noexcept ;
    ~MyInt() ;
    MyInt& operator=(const MyInt& other) ;
    MyInt& operator=(MyInt&& other) noexcept ;
    int getValue() const ;
    void setValue(int value) ;
};

#endif
