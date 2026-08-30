#include <iostream>
#include <array>
using namespace std;
array<array<int,2>,2> aget();
//void ashow(array<array<int,2>,2> a);
void rowT(array<array<int, 2>, 2> arr)
{
	int sum;
	for (int i = 0; i<2; i++)
	{
		 sum = 0;
		
		for (int j = 0; j<2; j++)
		{
			sum = sum + arr[i][j];
			cout << arr[i][j] << " ";
		}
		cout << sum << endl;
	}
}


int main()
{
	array<array<int,2>,2> v;
	cout<<"enter data";
    v = aget();
    rowT(v);
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

/*void ashow(array<array<int,2>,2> data)
{
    int j = 0;
    while(j < 2)
    {
        int k = 0;
        while(k < 2)
        {
            cout << data[j][k] << "  ";
            k = k + 1;
        }
        cout << endl;
        j = j + 1;
    }
}*/