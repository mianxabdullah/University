#include "TempStack.h"

// TASK :3
bool validateExpression(const string &expr)
{
    Stack<char> st(expr.length());
    for (char ch : expr)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (st.isEmpty())
                return false;
            char topChar = st.pop();
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '['))
            {
                return false;
            }
        }
    }
    return st.isEmpty();
}
bool isGood(string s)
{
    bool r;
    r = validateExpression(s);
    return r;
}

int main()
{
    string exp = "3+3";
    cout << "IS GOOD: " << (isGood(exp) ? "yes" : "no") << endl;
}
