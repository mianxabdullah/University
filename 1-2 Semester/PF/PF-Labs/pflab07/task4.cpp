#include<iostream>
#include<array>
using namespace std;
struct ratio
{
    int num;
    int den;
};
int main()
{
    int r;
    int s;
    int num;
    ratio a[50];
    cout<<"Enter number of ratios you want to enter:";
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cout<<"Enter ratio no."<<i+1<<endl;
        cin>>a[i].num;
        cin>>a[i].den;
        if(a[i].den==0)
        {
            cout<<"invalid prompt";
            exit(5);
            return 5;
        }

    }
    r=a[0].num*a[1].num;
    s=a[0].den*a[1].den;
    for(int i=2;i<num;i++)
    {
        r=r*a[i].num;
        s=s*a[i].den;
    }
    cout<<"Product of several ratios is:";
    cout<<r<<"/"<<s;
}
