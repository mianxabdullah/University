#include<iostream>
#include<string>
using namespace std;
int main()
{
    int s,e,n;
    cout<<"Enter starting and ending number:";
    cin>>s>>e;
    n=e*(e+1)/2-(s-1)*s/2;
    cout<<"The sum of given range is:"<<n<<endl;
    return 0;
    
}