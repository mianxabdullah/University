#include"Stack.h"

    Stack::Stack(int c)
    {
        if(c>0)
        {
            capacity=c;
            top=0;
            data=new int[c];
            for(int i=0;i<c;i++)
            {
                data[i]=0;
            }
        }
        else
        {
            exit(0);
        }
    }
    Stack::Stack(const Stack& rhs)
    {
        top=rhs.top;
        capacity=rhs.capacity;
        data=new int[capacity];
        for(int i=0;i<top;i++)
        {
            data[i]=rhs.data[i];
        }
    }
    Stack& Stack::operator=(const Stack& rhs)
    {
        if(this != &rhs)
        {
            delete[] data;
            top=rhs.top;
            capacity=rhs.capacity;
            data=new int[capacity];
            for(int i=0;i<top;i++)
            {
                data[i]=rhs.data[i];
            }
        }
        return *this;
    }
    Stack::~Stack()
    {
        delete[] data;
    }
    void Stack::push(int a)
    {
        if(top!=capacity)
        {
            data[top]=a;
            top++;
        }
    }
    int Stack::pop()
    {
        if(top>0)
        {
            top--;
            return data[top];
        }
    }
    bool Stack::isFull()
    {
        if(top==capacity)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool Stack::isEmpty()
    {
        if(top==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int Stack::getTop()
    {
        return top;
    }
    int Stack::StackTop()
    {
        if(top!=0)
        {
            return data[top-1]; //it just shows or returns top value without removing it
        }
        else
        {
            throw runtime_error("stack is empty");
        }
    }

