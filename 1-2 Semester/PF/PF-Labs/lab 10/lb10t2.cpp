#include <iostream>
#include <string>
#include <array>
using namespace std;
void swap(float &a, float &b) 
{
    float temp = a;
    a = b;
    b = temp;
}
void rearrangeArray(array<float,12>&arr) 
{
    float pivot = arr[11]; 
    int pivotIndex = 0;
    for (int i = 0; i < 11; i++) 
	{
        if (arr[i] <= pivot) 
		{
            swap(arr[i], arr[pivotIndex]);
            pivotIndex++;
        }
    }
    swap(arr[pivotIndex], arr[11]);
}
void printArray(array<float,12>&arr) 
{
    for (int i = 0; i < 12; i++)
	{
        cout<< arr[i] << " ";
    }
    cout<<endl;
}

int main() 
{
    array<float,12>arr= {23, 54, 12, 19, 67, 9, 45, 32, 90, 58, 19, 48};
    cout << "Original array: ";
    printArray(arr);
	rearrangeArray(arr);
    cout<<"Rearranged array: ";
    printArray(arr);
}
