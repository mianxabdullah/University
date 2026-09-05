#include"TempStack.h"
template <typename T>
class que
{
public:
    Stack<T> s1;
    Stack<T> s2;
    que(){}
    void push(T a)
    {
        s1.push(a);
    }
    int pop()
    {
        if(s1.isEmpty() && s2.isEmpty())
        {
            throw runtime_error("Queue is empty");
        }
        if(s2.isEmpty())
        {
            while(!s1.isEmpty())
            {
                s2.push(s1.pop());
            }
        }
        int front=s2.pop();
        return front;
    }
    int peek()
    {
        if(s1.isEmpty() && s2.isEmpty())
        {
            throw runtime_error("Queue is empty");
        }
        if(s2.isEmpty())
        {
            while(!s1.isEmpty())
            {
                s2.push(s1.pop());
            }
        }
        return s2.top();
    }
    bool empty()
    {
        return s1.isEmpty() && s2.isEmpty();
    }


};