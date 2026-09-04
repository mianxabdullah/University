#include <iostream>
#include "Stack.h"

using namespace std;

bool isAsBt(string s)
{
    int n = s.length();
    if (n == 0)
        return true;

    myStack<char> AB(s.length());

    bool foundB = false;
    int i = 0;

    while (i < n)
    {
        if (s[i] == 'a')
        {
            if (foundB)
                return 0;
            AB.push(s[i]);
        }

        else if (s[i] == 'b')
        {
            foundB = true;
            AB.push(s[i]);
        }

        i++;
    }
    return 1;
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << (isAsBt(s) ? "Valid" : "Invalid");
}