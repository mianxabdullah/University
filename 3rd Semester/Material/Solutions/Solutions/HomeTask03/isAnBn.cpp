#include <iostream>
#include "Stack.h"

using namespace std;

bool isAnBn(string s)
{
    int n = s.length();
    if (n == 0)
        return 1;

    if (n % 2 != 0)
        return 0;

    myStack<char> AB(s.length());

    int i = 0;
    while (i < n && s[i] == 'a')
    {
        AB.push(s[i]);
        i++;
    }

    while (i < n && s[i] == 'b')
    {
        if (AB.isEmpty())
            return 0;
        AB.pop();
        i++;
    }

    return (i == n && AB.isEmpty());
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << (isAnBn(s) ? "Valid" : "Invalid");
}