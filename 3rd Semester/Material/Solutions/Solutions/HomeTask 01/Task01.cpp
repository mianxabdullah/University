        #include <iostream>
using namespace std;

void allocateArray(int ***&arr, int d1, int d2, int d3)
{
    arr = new int **[d1];
    for (int i = 0; i < d1; i++)
    {
        *(arr + i) = new int *[d2];
        for (int j = 0; j < d2; j++)
        {
            *(*(arr + i) + j) = new int[d3];
        }
    }
}

void initializeArray(int ***&arr, int d1, int d2, int d3)
{
    for (int i = 0; i < d1; i++)
    {
        for (int j = 0; j < d2; j++)
        {
            for (int k = 0; k < d3; k++)
            {
                *(*(*(arr + i) + j) + k) = rand() % 100;
            }
        }
    }
}

void printArray(int ***&arr, int d1, int d2, int d3)
{
    for (int i = 0; i < d1; i++)
    {
        for (int j = 0; j < d2; j++)
        {
            for (int k = 0; k < d3; k++)
            {
                cout << *(*(*(arr + i) + j) + k) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void deallocateArray(int ***&arr, int d1, int d2, int d3)
{
    for (int i = 0; i < d1; i++)
    {
        for (int j = 0; j < d2; j++)
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
    int ***data;
    allocateArray(data, 2, 3, 4);
    initializeArray(data, 2, 3, 4);
    printArray(data, 2, 3, 4);
    deallocateArray(data, 2, 3, 4);
    return 0;
}