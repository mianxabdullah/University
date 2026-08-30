#include <iostream>
#include <array>
using namespace std;
array<array<int,2>,2> aget();
void rowColT(array<array<int, 2>, 2> arr)
{
	array<int, 2> sumR = {0, 0};
	array<int, 2> sumC = {0, 0};
	
	for (int i = 0; i<2; i++)
	{	
		for (int j = 0; j<2; j++)
		{
			sumR[i] = sumR[i] + arr[i][j];
			sumC[j] = sumC[j] + arr[i][j];
		}
	}
	
	cout << "   ";
	
	for (int i = 0; i<2; i++)
	{
		cout << sumC[i] << " ";
	}
	cout << endl;
	
	for (int i = 0; i<2; i++)
	{
		cout << sumR[i] << " "; //sum of rows on left
		
		for (int j = 0; j<2; j++)
		{			
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	array<array<int,2>,2> v;
	cout<<"enter data";
    v = aget();
    rowColT(v);
    
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

