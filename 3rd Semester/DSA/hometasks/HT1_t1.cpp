#include <iostream>
using namespace std;

void allocateArray (int*** &arr, int n = 3)
{
    arr = new int**[n];
    for (int i = 0; i < n; i++)
    {
        *(arr + i) = new int*[n];
        for (int j = 0; j < n; j++)
        {
            *(*(arr + i) + j) = new int[n];
        }
    }
} 

void initializeArray (int*** &arr, int n = 3)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                *(*(*(arr + i) + j) + k) = i + 1; 
            }
        }
    }
} 

void printArray (int*** &arr, int n = 3)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Layer " << i+1 << ":\n";
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cout << *(*(*(arr + i) + j) + k) << " "; 
            }
            cout << endl;
        }
        cout << endl;
    }
}

void deallocateArray (int*** &arr, int n = 3)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            delete[] *(*(arr + i) + j);
        }
        delete[] *(arr + i);
    }
    delete[] arr;
    arr = nullptr; 
}

int main()
{
    int*** ptr = nullptr;
    int size = 3;

    allocateArray(ptr, size);
    initializeArray(ptr, size);
    printArray(ptr, size);
    deallocateArray(ptr, size);

    return 0;
}