#include <array>
#include <iostream>
using namespace std;
int main()
{
	int sum=0;
	int* ar= new int [6];
	cout<<"enter some values";
	for(int i=-3;i<3;i++)
	{
		cin>>ar[i];
	}
	
	int** ptr=&ar;
	for(int i=-3;i<3;i++)
	{
		sum=sum+*(ptr[i]);
	}
	cout<<"sum is :"<<sum;
    ptr=NULL;
}