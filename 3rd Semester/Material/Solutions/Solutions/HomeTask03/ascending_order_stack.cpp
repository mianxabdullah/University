#include<iostream>
#include"Stack.h"   

using namespace std;

void ascending_order(myStack<int> & s)
{
    myStack<int> Stack1(s.getCapacity());
    
    while (!s.isEmpty())
    {
        int temp = s.pop();

        while(!Stack1.isEmpty() && Stack1.stackTop() > temp)
        {
            s.push(Stack1.pop());
        }
        Stack1.push(temp);
    }

    while (!Stack1.isEmpty())
    {
        s.push(Stack1.pop());
    }
    
    
}

int main()
{
    myStack<int> s(10);
    s.push(4);
    s.push(1);
    s.push(8);
    s.push(2);
    s.push(5);
    
    cout << "Initial stack size: " << s.getTop() << endl;
    
    ascending_order(s);
    
    cout << "Final stack size: " << s.getTop() << endl; 
    cout << "Result: ";
    while (!s.isEmpty())
    {
        cout << s.pop() << " ";
    }
    cout << endl;
    
    return 0;
}