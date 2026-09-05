// #ifndef MAXHEAP_H
// #define MAXHEAP_H
#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
class MaxHeap
{
private:
    int height;
    int noe;
    T *data;
    int size;

    void heap_up(int i)
    {
        int parent = (i - 1) / 2;
        while (i != 0 && data[i] > data[parent])
        {
            swap(data[i], data[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }

    void heap_down(int i)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int max = i;
        if (left < noe && data[left] > data[max])
            max = left;
        if (right < noe && data[right] > data[max])
            max = right;
        if (max != i)
        {
            swap(data[i], data[max]);
            heap_down(max);
        }
    }

public:
    MaxHeap(int h)
    {
        height = h;
        noe = 0;
        size = pow(2, h) - 1;
        data = new T[size];
    }

    ~MaxHeap()
    {
        delete[] data;
    }

    void Insert(T val)
    {
        if (noe < size)
        {
            data[noe] = val;
            noe++;
            int i = noe - 1;
            heap_up(i);
        }
    }

    void remove(int i)
    {
        if (noe > i)
        {
            swap(data[noe - 1], data[i]);
            noe--;
            heap_down(i);
            heap_up(i);
        }
    }

    T getMaximum()
    {
        if (noe > 0)
        {
            return data[0];
        }
    }

    void delete_maximum()
    {
        if (noe == 0)
            return;
        swap(data[noe - 1], data[0]);
        noe--;
        heap_down(0);
    }

    int heapsize()
    {
        if (noe > 0)
        {
            return noe;
        }
    }

    bool isEmpty()
    {
        return (noe == 0);
    }

    void increaseKey(int i, int nval)
    {
        if (i < noe)
        {
            data[i] = nval;
            heap_up(i);
        }
    }

    void decreaseKey(int i, int nval)
    {
        if (i < noe)
        {
            data[i] = nval;
            heap_down(i);
        }
    }

    void build_from_array(T arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            data[i] = arr[i];
        }
        noe = n;
        int i = (n / 2) - 1;
        while (i >= 0)
        {
            heap_down(i);
            i--;
        }
    }

    void printHeap()
    {
        for (int i = 0; i < noe; i++)
            cout << data[i] << " ";
        cout << endl;
    }
    int getHeight()
    {
        return height;
    }
    int capacity()
    {
        return size;
    }
    void clear()
    {
        noe = 0;
    }
    void replaceRoot(T val)
    {
        if (noe == 0)
            return;
        data[0] = val;
        heap_down(0);
    }

    
    void heapify_down(int arr[],int i,int n)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int max = i;
        if (left < n && arr[left] > arr[max])
            max = left;
        if (right < n && arr[right] > arr[max])
            max = right;
        if (max != i)
        {
            swap(arr[i], arr[max]);
            heapify_down(arr,max,n);
        }
    }
    
    void heapSort(int arr[],int n)
    {
        for(int i=(n/2)-1;i>=0;i--)
            heapify_down(arr,i,n);
        for(int j=n-1;j>0;j--)
        {
            swap(arr[j],arr[0]);
            heapify_down(arr,0,j);
        }
    }
};
// #endif
int main()
{
    MaxHeap<int> h(4);
    cout << "Inserting values...\n";
    h.Insert(20);
    h.Insert(5);
    h.Insert(15);
    h.Insert(30);
    h.Insert(2);
    h.Insert(10);

    cout << "Deleting maximum...\n";
    h.delete_maximum();
    cout << "Increasing key at index 0 to 50...\n";
    h.increaseKey(0, 50);
    cout << "Decreasing key at index 3 to 1...\n";
    h.decreaseKey(3, 1);
    cout << "Removing element at index 2...\n";
    h.remove(2);

    
    int arr[10]={1,5,2,7,6,4,11,21,16,12};
    MaxHeap<int> m(5);
    m.heapSort(arr,10);
    for(int i = 0; i < 10; i++)
    cout << arr[i] << " ";
    cout << endl;
}
