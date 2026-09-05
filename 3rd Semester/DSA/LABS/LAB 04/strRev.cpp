#include "TempStack.h"
string reverseWords(const string &str)
{
    string abc=" ";
    string ans="";
    Stack<char>a(str.length());
    for(int i=0;i<str.length();i++)
    {
        if(isalpha(str[i]))
        {
            a.push(str[i]);
        }
        if(str[i]==abc[0] || str[i]==str[str.length()-1])
        {
            while(!a.isEmpty())
            {
                char ab=a.pop();
                ans+=ab;
            }
            ans+=" ";
        }
    }
    return ans;
}
int main()
{
    string s="Welcome to DSA";
    cout<<reverseWords(s);
}