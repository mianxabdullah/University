#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    int n;
    int sum=0;
    cout<<"Enter the number:";
    cin>>n;
    int i=1;
    while(i<=n)
    {
        if(n%i==0)
        {
            cout<<i<<endl;
            sum=sum+i;
        }
        i=i+1;
    }
    cout<<"The sum of factors is:"<<sum<<endl;
    return 0;
}