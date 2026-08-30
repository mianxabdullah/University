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
	int x,y,z;
	int lcm;
	cout<<"enter two numbers"<<endl;
	cin>>x>>y;
	z=x*y;
	z=abs(z);
	lcm=z/hcf(x,y);
	cout<<"lcm is: "<<lcm;	
}