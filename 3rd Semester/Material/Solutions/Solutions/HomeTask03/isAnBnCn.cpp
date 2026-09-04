#include <iostream>
#include "Stack.h"

using namespace std;

bool isAnBnCn(string s)
{
    int n = s.length();
    if (n == 0)
        return true;

    myStack<char> ABC(s.length());

    int i = 0;
    int countC = 0;
    while (i < n && s[i] == 'a')
    {
        ABC.push(s[i]);
        i++;
    }

    while (i < n && s[i] == 'b')
    {
        if (ABC.isEmpty())
            return false;
        ABC.pop();
        i++;
    }

    while(i < n && s[i] == 'c')
    {
        countC++;
        i++;
    }

    return ((i == n) && (countC == n/3) && (n % 3 == 0));
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << (isAnBnCn(s) ? "Valid" : "Invalid");
}