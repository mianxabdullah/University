#include<iostream>
#include<string>
using namespace std;
float distance(float vi, float ac, float tm)
{
    float dis;
    dis=vi*tm+(0.5)*ac*tm*tm;
    return dis;
}
int main()
{
    float v,a,t;
    cout<<"Enter velocity,acc and time:";
    cin>>v>>a>>t;
    cout<<"The distance covered is:"<<distance(v,a,t)<<endl;
    return 0;
}