#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

string reverseWords(string str)
{
    myStack<char> charStack(str.length());
    string rev = "";
    
    for(int i = 0; i < str.length(); i++)
    {
        if(isalpha(str[i]))
        {
            charStack.push(str[i]);
        }
        if(str[i] == ' ' || i == str.length() - 1)
        {
            while(!charStack.isEmpty())
            {
                rev = charStack.pop() + rev;
            }
            if(str[i] == ' ')
            rev = ' ' + rev;
        }
    }

 
    return rev;
}

int main()
{
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    string reversed = reverseWords(input);

    cout << "Original: " << input << endl;
    cout << "Reversed: " << reversed << endl;

    return 0;
}