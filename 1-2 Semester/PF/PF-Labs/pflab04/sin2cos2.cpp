#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    float d;
    int r;
    cout<<"Enter degrees:";
    cin>>d;
    r=(sin(d)*sin(d)+cos(d)*cos(d));
    cout<<r<<endl;
    return 0;
}