#include<iostream>
#include<string>
#include<array>
using namespace std;
string isprime(int n)
{
	string r="prime";
	int i=2;
	while(i<n)
	{
		if(n%i==0)
		{
			r="not prime";
		}
		i++;
	}
	return r;
}
int main()
{
	int n;
	cout<<"enter a number";
	cin>>n;
	cout<<isprime(n);
}