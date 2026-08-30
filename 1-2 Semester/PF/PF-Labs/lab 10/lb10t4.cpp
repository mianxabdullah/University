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
// Function to merge two sorted subarrays
void merge(array<float,20>&arr, int start, int mid, int end) 
{
    int i = start, j = mid + 1, k = start;
    while (i <= mid && j <= end) 
	{
        if (arr[i] <= arr[j]) 
		{
            k++;
            i++;
        } 
		else 
		{
            swap(arr[k], arr[j]);
            k++;
            j++;
             // Shift elements to the right to make space for the swapped element
            for (int l = k; l > i; l--) 
			{
                swap(arr[l], arr[l - 1]);
            }
        }
    }
}
void sortArray(array<float,20>&arr, int start, int mid, int end) 
{
    merge(arr, start, mid, end);
}
void printArray(array<float,20>&arr) 
{
    for (int i = 0; i < 20; i++)
	{
        cout << arr[i] << " ";
    }
    cout<<endl;
}
int main() 
{
    array<float,20>arr = {7, 12, 25, 45, 82, 97, 3, 34, 38, 40, 49, 52, 65, 83, 91, 92, 94, 95, 96};
    int start = 0, mid = 5, end = 19;
    cout << "Original array: ";
    printArray(arr);
    sortArray(arr, start, mid, end);
	cout << "Sorted array: ";
    printArray(arr);
}
