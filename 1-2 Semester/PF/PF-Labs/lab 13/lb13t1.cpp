#include <algorithm>
#include <iostream>
#include <array>
using namespace std;
int main()
{
	int n;
	cout<<"enter size of array ";
	cin>>n;
	int sum=0;
	int* ar= new int [n];
	cout<<"enter some values";
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
		sum=sum+ar[i];
	}
	cout<<"sum is :"<<sum;
	delete []ar;
	ar=NULL;
}