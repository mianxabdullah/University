#include<iostream>
#include"Stack.h"

using namespace std;

void reverse_stack_order(myStack<int> &S)
{
    myStack<int> Stack1(S.getCapacity());
    myStack<int> Stack2(S.getCapacity());
    while(!S.isEmpty()) //store s in s1 
    {
        Stack1.push(S.pop());
    }
    while(!Stack1.isEmpty()) 
    {
        Stack2.push(Stack1.pop());
    }
    while(!Stack2.isEmpty())
    {
        S.push(Stack2.pop());
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