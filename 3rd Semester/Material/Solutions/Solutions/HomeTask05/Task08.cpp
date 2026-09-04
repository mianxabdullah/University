#include<iostream>
using namespace std;

void bit_strings(string s , int len)
{
    if(s.length() == len)
    cout << s << endl;
    else
    {
        bit_strings(s + "0" , len);
        bit_strings(s + "1" , len);
    }
}

int main()
{
    bit_strings("" , 4);
}
