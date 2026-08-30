#include<iostream>
#include<cmath>
using namespace std;
int octdec(int n)
{
    int i=0;
    int dec=0;
    while(i<n)
    {
        int digit=n%10;
        dec=dec+digit*pow(8,i);
        n=n/10;
        i=i+1;
    }
    return dec;
}
int main()
{
    int a;
    cout<<"Enter number is octal:";
    cin>>a;
    cout<<"The equivalent decimal number is:"<<octdec(a)<<endl;
    return 0;
}