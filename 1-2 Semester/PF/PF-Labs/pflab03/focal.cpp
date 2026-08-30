#include<iostream>
#include<string>
using namespace std;
float fl(float p, float q)
{
    float foc;
    foc=1/((1/p)+(1/q));
    return foc;
}
int main()
{
    float P,Q;
    cout<<"Enter p and q:";
    cin>>P>>Q;
    cout<<"The focal length is:"<<fl(P,Q)<<endl;
    return 0;
}