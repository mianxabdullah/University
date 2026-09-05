#ifndef STACK.H
#define STACK.H
#include<iostream>
using namespace std;
class Stack
{
protected:
    int* data;
    int capacity; //capacity of data array
    int top; //no of elements
public:
    Stack(int c);
    Stack(const Stack& rhs);
    Stack& operator=(const Stack& rhs);
    ~Stack();
    void push(int a);
    int pop();
    bool isFull();
    bool isEmpty();
    int getTop();
    int StackTop();
};
#endif