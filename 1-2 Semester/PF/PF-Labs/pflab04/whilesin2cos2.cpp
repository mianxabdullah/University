#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    float i=0;
    double r;
    while(i<=3.14)
    {
        r=(pow(sin(i),2)+pow(cos(i),2));
        cout<<r<<endl;
        i=i+0.01;
    }
    return 0;
}
