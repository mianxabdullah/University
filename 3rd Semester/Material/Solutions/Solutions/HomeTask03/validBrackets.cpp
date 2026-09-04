#include <iostream>
#include "Stack.h"

using namespace std;

bool validBraces(string s)
{
    myStack<char> braces(s.length());

    for (char ch : s)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            braces.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (braces.isEmpty())
                return 0;
            if ((ch == ')' && braces.stackTop() == '(') || (ch == '}' && braces.stackTop() == '{') || (ch == ']' && braces.stackTop() == '['))
                braces.pop();
            else
                return 0;
        }
    }
    return braces.isEmpty();
}

int main()
{
    string s = "[A+{B-(C * D)}]";
    cout << validBraces(s) << endl; 
    
    string s2 = "[A+{B-(C * D)}";
    cout << validBraces(s2) << endl; 
    
    string s3 = "[A+{B-(C * D)}]]"; 
    cout << validBraces(s3) << endl; 
    
    return 0;
}