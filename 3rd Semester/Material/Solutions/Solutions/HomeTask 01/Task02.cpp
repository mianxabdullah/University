#include <iostream>
using namespace std;

class myArray
{
private:
    int *arr;
    int size;
    int row_size;

public:
    myArray(int i = 0, int j = 0)
    {
        size = i * j;
        arr = new int[size];
        row_size = i;
    }
    ~myArray()
    {
        delete[] arr;
    }
    myArray(const myArray &other)
    {
        delete[] arr;
        for (int i = 0; i < other.size; i++)
        {
            arr[i] = other.arr[i];
        }
        size = other.size;
    }
    int getIndexValue(int i, int j)
    {
        return *(arr + (j * row_size + i));
    }
    void setIndexValue(int i, int j, int val)
    {
        *(arr + (j * row_size + i)) = val;
    }
    void printArray()
    {
        for (int i = 0; i < row_size; i++)
        {
            for (int j = 0; j < size / row_size; j++)
            {
                cout << *(arr + (j * row_size + i)) << " ";
            }
            cout << endl;
        }
    }
    void addressOfIndex(int i, int j, int *&StartIndex)
    {
        int offset = j * row_size + i;
        StartIndex = arr + offset;
    }
    myArray operator+(const myArray &other)
    {
        myArray ans(2, 3);
        for (int i = 0; i < row_size; i++)
        {
            for (int j = 0; j < size / row_size; j++)
            {
                *(ans.arr + (j * row_size + i)) = *(arr + (j * row_size + i)) + *(other.arr + (j * row_size + i));
            }
        }
        return ans;
    }
    void printSubArray(int r1, int r2, int c1, int c2)
    {
        for (int i = r1; i <= r2; i++)
        {
            for (int j = c1; j <= c2; j++)
            {
                cout << *(arr + (j * row_size + i)) << " ";
            }
            cout << endl;
        }
    }
    void clear(int m, int n)
    {
        for (int i = m; i <= n; i++)
        {
            for (int j = m; j <= n; j++)
            {
                *(arr + (j * row_size + i)) = 0;
            }
        }
    }
};

int main()
{
    myArray arr1(2, 3);
    arr1.setIndexValue(0, 0, 1);
    arr1.setIndexValue(0, 1, 2);
    arr1.setIndexValue(0, 2, 3);
    arr1.setIndexValue(1, 0, 4);
    arr1.setIndexValue(1, 1, 5);
    arr1.setIndexValue(1, 2, 6);
    cout << arr1.getIndexValue(1, 1) << endl << endl;
    arr1.printArray();
    cout << endl;
    int *addr = nullptr;
    arr1.addressOfIndex(1, 1, addr);
    cout << addr << endl;
    cout << endl;
    myArray arr2(2, 3);
    arr2.setIndexValue(0, 0, 1);
    arr2.setIndexValue(0, 1, 2);
    arr2.setIndexValue(0, 2, 3);
    arr2.setIndexValue(1, 0, 4);
    arr2.setIndexValue(1, 1, 5);
    arr2.setIndexValue(1, 2, 6);
    myArray ans = arr1 + arr2;
    ans.printArray();
    cout << endl;
    myArray arr3(3, 3);
    arr3.setIndexValue(0, 0, 1);
    arr3.setIndexValue(0, 1, 2);
    arr3.setIndexValue(0, 2, 3);
    arr3.setIndexValue(1, 0, 4);
    arr3.setIndexValue(1, 1, 5);
    arr3.setIndexValue(1, 2, 6);
    arr3.setIndexValue(2, 0, 7);
    arr3.setIndexValue(2, 1, 8);
    arr3.setIndexValue(2, 2, 9);
    arr3.printSubArray(0, 1, 0, 2);
    cout << endl;
    arr3.clear(1, 2);
    arr3.printArray();
}