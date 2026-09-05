#include "TempStack.h"

// TASK:1
bool isPalindrom(string s)
{
    string str = "";
    string abc = " .?!,-(')";
    for (int i = 0; i < s.length(); i++) //make new str without special chars
    {
        if (s[i] != abc[0] && s[i] != abc[1] && s[i] != abc[2] && s[i] != abc[3] && s[i] != abc[4] && s[i] != abc[5] && s[i] != abc[6] && s[i] != abc[7] && s[i] != abc[8])
        {
            str.push_back(tolower(s[i]));
        }
    }
    bool r = true;
    Stack<char> st(str.length()); //push new str in stack
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != abc[0] && str[i] != abc[1] && str[i] != abc[2] && str[i] != abc[3] && str[i] != abc[4] && str[i] != abc[5] && str[i] != abc[6] && str[i] != abc[7] && str[i] != abc[8])
        {
            st.push(str[i]);
        }
    }
    for (int i = 0; i < str.length(); i++) // pop from stack  means its last element of str 
    {
        if (st.pop() != str[i])
        {
            return false;
        }
    }
    return r;
}

int main()
{
    string palind = "Dad?";
    cout << "IS PALINDROM: " << (isPalindrom(palind) ? "true" : "false") << endl;
}
