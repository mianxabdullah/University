#include<iostream>
#include<string>
#include<array>
using namespace std;
int productrange(int a,int b)
{
	int p=1;
	int i=a;
	while(i<=b)
	{
		p=p*i;
		i++;
	}
	return p;
}
int main()
{
	int a,b;
	cout<<"enter two numbers  ";
	cin>>a>>b;
	cout<<"products of numbers from "<<a<<" to "<<b<<" is "<<productrange(a,b);
}