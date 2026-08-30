#include<iostream>
#include<array>
using namespace std;
int search(int n,int v,array<int,50>arr)
{
	int index=-1;
	int i=0;
	while(i<n)
	{
		if(arr[i]==v)
		{
			index=i;
		}
		i++;
	}
	return index;
	
}
int main()
{
     int n,x;
     array<int,50>v;
     cout<<"How many numbers you want to enter:";
     cin>>n;
     int i=0;
     cout<<"Enter a number"<<endl;
     while(i<n)
     {
        cin>>v[i];
        i++;
     }
     cout<<"Enter the number you want to find:";
     cin>>x;
     int a=search(n,x,v);
    
    if(a!=-1)
    {
        cout<<"The value is at index"<<a;
    }
    else
    cout<<"value is not present";
}
