#include<iostream>
#include<array>
#include<cmath>
using namespace std;
int main()
{
    array<int,5>v;
    int i=0;
    int count=0;
    int n=1;
    while(i<5)
    {
        int a;
        cout<<"Enter a number"<<n<<":";
        cin>>a;
        if(a>-10000 && a<10000)
        {
            if(abs(a)>7000)
            {
                v[i]=a;
                count++;
                
            }
            i++;
        }
        n++;
    }
    cout<<"The numbers above 7000 are:"<<count<<endl;
    int x=5-count;
    cout<<"The numbers below 7000 are:"<<x<<endl;
    return 0;
}