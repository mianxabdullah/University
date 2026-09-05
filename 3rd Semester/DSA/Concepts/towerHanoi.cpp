#include<iostream>
using namespace std;
void tower(int n,char s,char d, char h)
{
    if(n==1)
    {
        cout<<s<<" "<<d<<endl;
    }
    else
    {
        tower(n-1,s,h,d);
        cout<<n<<" "<<s<<" "<<d<<endl;
        tower(n-1,h,d,s);
    }
}
int main()
{
    tower(3,'D','S','F');
}