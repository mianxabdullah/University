/*Write a function that accepts an array<float, 12> as parameter and return same type array
with rearranged values as described below.
Select the last element in array as a pivot, using logic place it at its position if the array is sorted. Also, array elements
before it should be less than or equal to it, and array elements after it should be greater than it. The
elements in the rearranged array are not required to be sorted. The catch is to complete this task with
simpler logic than sorting logic. You may use several arrays to complete this task.
parameter array: 23, 54, 12, 19, 67, 9, 45, 32, 90, 58, 19, 48
one possible return array: 23, 12, 19, 9, 45, 32, 19, 48, 54, 67, 90, 58 */

#include <iostream>
#include <string>
#include <array>
using namespace std;
void rearrangeArray(array<float,12>arr)
 {
    float pivot = arr[11];
    array<float,12>lessThanPivot,greaterThanPivot;
    int lessCount = 0, greaterCount = 0;
    for (int i = 0; i < 11; i++)
	{
        if (arr[i] <= pivot)
		{
            lessThanPivot[lessCount++] = arr[i];
        }
	    else 
		{
            greaterThanPivot[greaterCount++] = arr[i];
        }
    }
    for (int i = 0; i < lessCount; i++) 
	{
        arr[i] = lessThanPivot[i];
    }
    arr[lessCount] = pivot;
    for (int i = 0; i < greaterCount; i++) 
	{
        arr[lessCount + 1 + i] = greaterThanPivot[i];
    }
}
void printArray(array<float,12>arr) {
    for (int i = 0; i < 12; i++) 
	{
      cout << arr[i] << " ";
    }
    cout<<endl;
}

int main()
 {
    array<float,12>arr = {23, 54, 12, 19, 67, 9, 45, 32, 90, 58, 19, 48};
    cout << "Original array: ";
    printArray(arr);
    rearrangeArray(arr);
    cout << "Rearranged array: ";
    printArray(arr);
}


