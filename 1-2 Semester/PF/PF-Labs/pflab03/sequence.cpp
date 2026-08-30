#include<iostream>
#include<string>
#include<array>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cout<<"enter a numbers"<<endl;
	cin>>n;
	int i=0;
	while(i<n)
	{
	  cout<<pow(2,i)<<endl;
	  i++;
	}
}