#include <iostream>
using namespace std;
int main() 
{
    double* v[25];
    for (int i = 0; i < 25; i++) 
	{
        v[i] = new double[i + 1];
    }

    for (int i = 0; i < 25; i++) 
	{
        for (int j = 0; j < i + 1; j++) 
		{
            v[i][j] = (rand()%8)+2;
        }
    }

    for (int i = 0; i < 25; i++) 
	{
        for (int j = 0; j < 25- i - 1 ; j++) //for spaces from left
		{
            cout << " ";
        }
        for (int j = 0; j < i + 1; j++) //print stored random vals
		{
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 25; i++) 
	{
        delete[] v[i];
    }
}
