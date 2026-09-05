#ifndef STACK_H
#define STACK_H

#include <iostream>
#include<string>
#include <cmath>
using namespace std;
template <typename T>
class Stack
{
protected:
    T *data;
    int capacity; // capacity of data array
    int top;      // no of elements
public:
    Stack();
    Stack(int c);
    Stack(const Stack &rhs);
    Stack &operator=(const Stack &rhs);
    ~Stack();
    void push(T a);
    T pop();
    bool isFull();
    bool isEmpty();
    int getTop();
    T StackTop();
};
    template <typename T>
    Stack<T>::Stack()
    {
        top=0;
    }
    template <typename T>
    Stack<T>::Stack(int c)
    {
        if (c > 0)
        {
            capacity = c;
            top = 0;
            data = new T[c];
            for (int i = 0; i < c; i++)
            {
                data[i] = T();
            }
        }
        else
        {
            throw invalid_argument("Capacity must be positive");
        }
    }
    template <typename T>
    Stack<T>::Stack(const Stack &rhs)
    {
        top = rhs.top;
        capacity = rhs.capacity;
        data = new T[capacity];
        for (int i = 0; i < top; i++)
        {
            data[i] = rhs.data[i];
        }
    }
    template <typename T>
    Stack<T>& Stack<T>::operator=(const Stack &rhs)
    {
        if (this != &rhs)
        {
            delete[] data;
            top = rhs.top;
            capacity = rhs.capacity;
            data = new T[capacity];
            for (int i = 0; i < top; i++)
            {
                data[i] = rhs.data[i];
            }
        }
        return *this;
    }
    template <typename T>
    Stack<T>::~Stack()
    {
        delete[] data;
    }
    template <typename T>
    void Stack<T>::push(T a)
    {
        if (top != capacity)
        {
            data[top] = a;
            top++;
        }
    }
    template <typename T>
    T Stack<T>::pop()
    {
        if (top > 0)
        {
            top--;
            return data[top];
        }
        else
        {
            return 0;
        }
    }
    template <typename T>
    bool Stack<T>::isFull()
    {
        if (top == capacity)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    template <typename T>
    bool Stack<T>::isEmpty()
    {
        if (top == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    template <typename T>
    int Stack<T>::getTop()
    {
        return top;
    }
    template <typename T>
    T Stack<T>::StackTop()
    {
        if (top != 0)
        {
            return data[top - 1]; // it just shows or returns top value without removing it
        }
        else
        {
            throw runtime_error("stack is empty");
        }
    }
#endif