#include<iostream>
#include<string>
#include<array>
using namespace std;
int hcf(int a,int b)
{
	int hcf;
	int i=1;
	while(i<=a&&i<=b)
	{
		if(a%i==0&&b%i==0)
		{
			hcf=i;
		}
		i++;
	}
	return hcf;
}
int main()
{
	int x,y;
	cout<<"enter two numbers"<<endl;
	cin>>x>>y;
	cout<<"HCF of two numbers is: "<<hcf(x,y);
}