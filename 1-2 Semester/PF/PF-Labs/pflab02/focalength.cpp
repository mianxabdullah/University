#include<iostream>
#include<string>
using namespace std;
int main()
{
    float f,p,q;
    cout<<"Enter p and q:";
    cin>>p>>q;
    f=1/((1/p)+(1/q));
    cout<<"Focal length is:"<<f<<endl;
    return 0;
}