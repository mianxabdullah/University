#include <iostream>
#include <array>
using namespace std;
array<array<int,2>,2> aget();
int sumDia(array<array<int, 2>, 2> arr)
{
	int sum = 0;
	
	for (int i = 0; i<2; i++)
	{
		for (int j = 0; j<2; j++)
		{
			if (i==j)
			{
				sum = sum + arr[i][j];
			}
		}
	}
	
	return sum;
}


int main()
{
	array<array<int,2>,2> v;
	cout<<"enter data";
    v = aget();
    for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
    cout<<"sum of diagonal is: "<<sumDia(v);
}

array<array<int,2>,2> aget()
{
    array<array<int,2>,2> ar;
    int j = 0;
    while(j < 2)
    {
        int k = 0;
        while(k < 2)
        {
            cin >> ar[j][k];
            k = k + 1;
        }
        j = j + 1;
    }
    return ar;
}

