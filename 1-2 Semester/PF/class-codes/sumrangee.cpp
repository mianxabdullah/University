#include <iostream>
#include <string>
#include <array>
using namespace std;
int sumrange(int a,int b)
{
	int x=((a-1)*(a-1+1))/2;
	int y=(b*(b+1))/2;
	int sum=y-x;
	return sum;
}
int main()
{
	int i,j;
	cout<<"enter two numbers";
	cin>>i>>j;
	cout<<"sum of numbers between these two numbers "<<i<<" & "<<j<<"is : "<<sumrange(i,j);
}