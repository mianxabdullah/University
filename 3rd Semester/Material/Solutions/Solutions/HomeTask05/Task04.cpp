#include <iostream>
using namespace std;

int binary_search(int *arr, int left, int right, int target)
{
    if (left > right)
        return -1;
    int mid = (left + right) / 2;
    if (target == arr[mid])
    {
        return mid;
    }
    else
    {
        if (target < arr[mid])
        {
            return binary_search(arr, left, mid - 1, target);
        }
        else if (target > arr[mid])
        {
            return binary_search(arr, mid + 1, right, target);
        }
    }
}

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 67};
    int size = 9;
    int target = 45;

    int result = binary_search(arr, 0, size - 1, target);
    cout << "Element found at index: " << result << endl;

    return 0;
}