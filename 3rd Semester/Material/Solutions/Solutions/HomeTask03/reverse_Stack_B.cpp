#include <iostream>
#include "Stack.h"

using namespace std;

void reverse_stack_order(myStack<int> &S)
{
    myStack<int> Stack1(S.getCapacity());
    int n = S.getTop();

    for (int j = 0; j < n; j++)
    {
        int temp = S.pop();
        for (int i = j; i < n - 1; i++)
        {
            Stack1.push(S.pop());
        }
        S.push(temp);
        for(int i = j; i < n - 1; i++)
        {
            S.push(Stack1.pop());
        }
    }
}

int main()
{
    myStack<int> S(10);
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);
    reverse_stack_order(S);
    while (!S.isEmpty())
    {
        cout << S.pop() << " ";
    }
}