/*Write a function that accepts an array<float, 20> as its first parameter and return same type
array as sorted in ascending order. The array received should be sorted in ascending order
from the beginning up to some index near the middle of array. The rest of the array is also
sorted in ascending order. The other parameters of the function may be the location from
which up to which the first array is sorted. Again, the catch is to complete this task with simpler logic than sorting logic. You may use
several arrays to complete this task.
parameter array: 7, 12, 25, 45, 82, 97, 3, 34, 38, 40, 49, 52, 65, 83, 91
only possible return array: sorted in ascending order*/

#include <iostream>
#include <string>
#include <array>
using namespace std;
// Function to merge two sorted subarrays
void merge(array<float,20>arr, int start, int mid, int end) {
    float left[mid - start + 1], right[end - mid];
    int i, j, k;
    // Copy data to temporary arrays
    for (i = 0; i < mid - start + 1; i++)
        left[i] = arr[start + i];
    for (j = 0; j < end - mid; j++)
        right[j] = arr[mid + 1 + j];
    // Merge the temporary arrays
    i = 0; j = 0; k = start;
    while (i < mid - start + 1 && j < end - mid) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left, if any
    while (i < mid - start + 1) {
        arr[k] = left[i];
        i++; k++;
    }

    // Copy remaining elements of right, if any
    while (j < end - mid) {
        arr[k] = right[j];
        j++; k++;
    }
}

// Function to sort the array
void sortArray(array<float,20>arr, int start, int mid, int end) {
    // Call merge function to sort the array
    merge(arr, start, mid, end);
}
void printArray(array<float,20>arr) 
{
    for (int i = 0; i < 20; i++) 
	{
        cout << arr[i] << " ";
    }
    cout<<endl;
}
int main() {
    array<float,20>arr= {7, 12, 25, 45, 82, 97, 3, 34, 38, 40, 49, 52, 65, 83, 91, 92, 94, 95, 96};
    int start = 0, mid = 5, end = 19;
    cout << "Original array: ";
    printArray(arr);
    sortArray(arr, start, mid, end);
    cout << "Sorted array: ";
    printArray(arr);
}
