#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string per(int n)
{
    string i="false";
    int m=1;
    while(m<=n)
    {
        if(m*m==n)
        {
            i="true";
        }
        m=m+1;
    }
    return i;
}
int main()
{
    int r;
    cout<<"Enter a number:";
    cin>>r;
    cout<<"The number is a perfect square:"<<per(r)<<endl;
    return 0;
}