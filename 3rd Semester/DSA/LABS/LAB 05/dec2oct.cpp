#include<iostream>
using namespace std;
void dec2oct(int n)
{
    if(n==0)
    return ;
    if(n>0)
    {
        dec2oct(n/8);
        cout<<n%8;
    }
}
int main()
{
    int n=389;
    dec2oct(n);
}