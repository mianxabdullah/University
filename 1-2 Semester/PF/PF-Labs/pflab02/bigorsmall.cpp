#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cout<<"Enter a number:";
    cin>>n;
    if(n>=1000)
    {
        cout<<"Big number";
    }
    else
    {
        cout<<"Small number";
    }
    return 0;
}