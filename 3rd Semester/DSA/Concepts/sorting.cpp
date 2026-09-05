#include <iostream>
using namespace std;
/*
[5, 2, 4, 6, 1, 3]
Steps:
Start with the first element [5] — it’s already “sorted.”
Take 2, compare with 5, and insert it before → [2, 5]
Take 4, insert it between 2 and 5 → [2, 4, 5]
Take 6, it’s already larger than all → [2, 4, 5, 6]
Take 1, insert at the beginning → [1, 2, 4, 5, 6]
Take 3, insert between 2 and 4 → [1, 2, 3, 4, 5, 6]
*/
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i]; // Element to insert
        int j = i - 1;
        // Move elements that are greater than key
        // one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; // Insert key into correct position
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    insertionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}