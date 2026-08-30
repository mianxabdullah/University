#include <array>
#include <iostream>
using namespace std;
int main()
{
	int sum=0;
	int** ptr;
	for(int i=-3;i<3;i++)
	{
		cout<<*(ptr[i]);
		sum=sum+*(ptr[i]);
	}
	cout<<"sum is :"<<sum;
    ptr=NULL;
}