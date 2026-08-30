#include<iostream>
#include<array>
using namespace std;
int digitsum(int n)
{
    array<int,50>ar;
    int i=0;
    while(n>0)
    {
        ar[i]=n%10;
        n=n/10;
        i=i+1;
    }
    int s=0;
    int x=0;
    while(x<i)
    {
        s=s+ar[x];
        x=x+1;
    }
    return s;
}
int main()
{
    int a;
    cout<<"Enter a number:";
    cin>>a;
    cout<<"The sum digits is :"<<digitsum(a)<<endl;
    return 0;
}
