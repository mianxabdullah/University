#include "TempStack.h"


// TASK:2
bool isRepeated(string s)
{
    // Stack<char> st(s.length());
    bool r = true;
    int counta = 0;
    int countb = 0;
    if (s[0] != 'a')
    {
        r = false;
    }
    for (int i = 0; s[i] != 'b'; i++)
    {
        if (s[i] == 'a')
        {
            counta++;
            // st.push(s[i]);
        }
    }
    for (int j = counta; j < s.length(); j++)
    {
        if (s[j] == 'b')
        {
            countb++;
            // r=false;
        }
    }
    for (int j = counta; j < s.length(); j++)
    {
        if (s[j] == 'a')
        {
            r = false;
        }
    }
    if (counta != countb)
    {
        r = false;
    }

    return r;
}

int main()
{ 
    string an = "a";
    cout << "IS anbn: " << (isRepeated(an) ? "yes" : "no") << endl;
}
