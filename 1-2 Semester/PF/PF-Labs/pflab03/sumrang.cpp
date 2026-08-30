#include<iostream>
#include<string>
using namespace std;
int sumrange(int s, int e)
{
    int sumr;
    sumr=e*(e+1)/2-(s-1)*s/2;
    return sumr;
}
int main()
{
    int sn,en;
    cout<<"Enter starting and ending number:";
    cin>>sn>>en;
    cout<<"The sum of given range is:"<<sumrange(sn,en)<<endl;
    return 0;
}