#include <iostream>
#include <array>
using namespace std;
array<array<int,5>,5> aget()
{
    array<array<int,5>,5> ar;
    int j = 0;
    while(j < 5)
    {
        int k = 0;
        while(k < 5)
        {
            cin >> ar[j][k];
            k = k + 1;
        }
        j = j + 1;
    }
    return ar;
}

int main()
{
	array<array<int,5>,5> v,w;
	cout << "enter data of 1st array " << endl;
    v = aget();
    cout << "enter data of 2nd array " << endl;
	w = aget();
    cout << "You entered values: " << endl;
    int j = 0;
    while(j < 5)
    {
        int k = 0;
        while(k < 5)
        {
            cout << v[j][k]+w[j][k] << "  ";
            k = k + 1;
        }
        cout << endl;
        j = j + 1;
    }
    
	
}

