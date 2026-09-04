#include<iostream>
using namespace std;

string reverse (string s, int len)
{
    if(len == 0)
    return "";
    else
    {
        char curr = s[len-1];
        string rev = reverse(s , len - 1);
        string ans = curr + rev;
        return ans;
    }
}

int main()
{
    cout << reverse("huzaifa" , 7);
}