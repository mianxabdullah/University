#include <iostream>
#include <array>

using namespace std;

array<array<int,5>,5> aget();
void ashow(array<array<int,5>,5> a);
void scalar(array<array<int,5>,5> data,int n);

int main()
{
	int n;
	cout<<"enter a number for scalar product"<<endl;
	cin>>n;
	array<array<int,5>,5> v;
	cout<<"enter data of array :"<<endl;
    v = aget();
    scalar(v,n);
}

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

void scalar(array<array<int,5>,5> data,int n)
{
    int j = 0;
    while(j < 5)
    {
        int k = 0;
        while(k < 5)
        {
            cout << n*data[j][k] << "  ";
            k = k + 1;
        }
        cout << endl;
        j = j + 1;
    }
}
