#include<iostream>
#include <string>
#include <algorithm>
#include <array>
using namespace std;
int main()
{
	double a=77.2;
	double b=5.5;
	double *p;
	double *i;
	p=&a;
	i=&b;
	if(*p>*i)
	{
	  cout<<*p<<" is greater";	
	}
	else
	{
		cout<<*i<<" is greater";
	}
}