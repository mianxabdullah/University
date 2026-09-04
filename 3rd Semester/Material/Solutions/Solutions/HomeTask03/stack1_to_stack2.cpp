#include<iostream>
#include"Stack.h"

using namespace std;

myStack<int> stack1_to_stack2(myStack<int> s1)
{
    myStack<int> s2(s1.getCapacity());
    int n = s1.getTop();

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n-1; j++)
        {
            s2.push(s1.pop());
        }
        int temp = s1.pop();
        for(int j = i; j < n-1; j++)
        {
            s1.push(s2.pop());
        }
        s2.push(temp);
    }
    return s2;
}

int main()
{
    myStack<int> s1(10);
    s1.push(3);
    s1.push(1);
    s1.push(5);
    s1.push(7);
    myStack<int> s2(s1.getCapacity());
    s2 = stack1_to_stack2(s1);
    while (!s2.isEmpty())
    {
        cout << s2.pop() << " ";
    }
    cout << endl;
}