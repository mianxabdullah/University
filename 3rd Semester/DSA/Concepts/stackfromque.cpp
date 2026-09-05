#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Stack
{
    queue<T> q1, q2;

public:
    void push(T x)
    {
        // Step 1: Push new element into q2
        q2.push(x);

        // Step 2: Move all elements from q1 → q2
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        // Step 3: Swap q1 and q2
        swap(q1, q2);
    }

    void pop()
    {
        if (q1.empty())
            throw runtime_error("Stack is empty");

        q1.pop(); // top element is always at front
    }

    T top()
    {
        if (q1.empty())
            throw runtime_error("Stack is empty");

        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};
