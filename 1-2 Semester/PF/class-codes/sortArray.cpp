#include<iostream>
#include<string>
#include<array>

using namespace std;

array<int, 100> sortArray(array<int, 100> a, int n);

int main()
{   int n;
	array<int, 100> ar; 
	cout<<"enter data size"<<endl;
	cin>>n;
	cout<<"enter array data one by one"<<endl;
	for(int x=0;x<n;x++)
	{ 
	  cin>>ar[x];
	}
	array<int, 100> sar = sortArray(ar, n);
	int k = 0;
	cout<<"sorted array is:"<<endl;
	while (k < n)
	{
		cout << sar[k] << endl;
		k = k+1;
	}
	return 0;
}

array<int, 100> sortArray(array<int, 100> a, int n)
{
	array<int, 100> arr = a;
	for(int i = 0;i<n-1;i++)
	{
		for(int j = i+1;j<n;j++)
		{
			if (arr[j] < arr[i])
			{ 
		    	int temp=arr[j];
			    arr[j]=arr[i];
				arr[i]=temp;
			}
		}
	}
	
	return arr;
}
