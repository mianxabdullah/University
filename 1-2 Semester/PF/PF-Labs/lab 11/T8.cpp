#include <iostream>
#include <array>
#include <cmath>
using namespace std;


bool isSymmetric(array<array<int, 5>, 5> arr)
{
	bool sym = true;
	
	int mid = 1;
	int maxIndex = 4;
	
	for (int i = 0; i<5; i++)
	{
		for (int j = 0; j<=mid; j++)
		{
			if (arr[i][j] != arr[i][maxIndex-j])
			{
				sym = false;
			}
		}
	}
	
	return sym;
}



int main()
{
	array<array<int, 5>, 5> arr = {{{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}}};

	
	if (isSymmetric(arr) == 1)
	{
		cout << "Matrix is symmetrical" << endl;
	}
	else
	{
		cout << "Matrix is not symmetrical" << endl;
	}
	
}