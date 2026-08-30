#include<iostream>
#include<string>
#include<array>
using namespace std;
int fact(int n)
{
	int f=1;
	int i=1;
	while(i<=n)
	{
		f=f*i;
		i++;
	}
	return f;
}
int main()
{
	int n;
	cout<<"enter a number ";
	cin>>n;
	cout<<"factorial of "<<n<<" is  "<<fact(n);
}