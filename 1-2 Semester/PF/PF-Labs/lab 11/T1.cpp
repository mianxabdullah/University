#include <iostream>
#include <array>

using namespace std;

array<array<int,2>,2> aget();
void ashow(array<array<int,2>,2> a);

int main()
{
	array<array<int,2>,2> v;
    v = aget();
	
    cout << "You entered values: " << endl;
    ashow(v);
	return 0;
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

void ashow(array<array<int,2>,2> data)
{
    int j = 0;
    while(j < 2)
    {
        int k = 0;
        while(k < 2)
        {
            cout << data[k][j] << "  "; //for transpose we changed data[j][k] with data[k][j]
            k = k + 1;
        }
        cout << endl;
        j = j + 1;
    }
}
