#include<iostream>
#include<string>
#include<cmath>
using namespace std;
float radians(float degree)
{
    float rad;
    rad=degree*(3.14/180);
    return rad;
}
int main()
{
    float degrees;
    cout<<"Enter degrees";
    cin>>degrees;
    cout<<"Angle in radians is:"<<radians(degrees)<<endl;
    return degrees;
}