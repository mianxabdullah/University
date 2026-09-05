#include <iostream>
using namespace std;
void formula (int n)
{
    if(n<=0)
    {
        cout<<"invalid";
    }
    for(int i=1;i<=n;i++)
    {
        cout<<"I"<<i;
        for(int j=i;j<n;j++)
        {
            cout<<"U"<<j+1;
        }
        if(i!=n)
        {
            cout<<" + ";
        }
    }
}
int main()
{
    cout<<"Formula: ";
    formula(11);
}