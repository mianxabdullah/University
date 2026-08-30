#include<iostream>
#include<string>
using namespace std;
struct ratio
{
    int num;
    int den;
};
ratio inratio();
void outratio(ratio a);
ratio inratio()
{
    ratio r;
    cin>>r.num;
    cin>>r.den;
    return r;
}
void outratio(ratio a)
{
    cout<<a.num;
    cout<<"/";
    cout<<a.den;
}
int main()
{
    ratio a;
    cout<<"Enter numerator and denominator:";
    a=inratio();
    if(a.den==0)
    {
        cout<<"the answer is not possible";
        exit(5);
        return 5;
    }
    cout<<"The ratio is:";
    outratio(a);
    return 0; 
}