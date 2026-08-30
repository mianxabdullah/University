#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string diff(int a, int b, int c)
{
    string r="ohhh";
    int d;
    d=a-b;
    if(abs(d)>abs(c))
    {
        r="waoo";
    }
    return r;
}
int main()
{
    int g,h,i;
    cout<<"Enter three numbers:";
    cin>>g>>h>>i;
    cout<<"The diff is:"<<diff(g,h,i)<<endl;
    return 0;
}