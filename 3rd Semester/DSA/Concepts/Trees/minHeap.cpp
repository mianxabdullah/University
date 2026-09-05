//#ifndef MINHEAP_H
//#define MINHEAP_H
#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
class MinHeap
{
private:
    int height;
    int noe;
    T *data;
    int size;

    void heap_up(int i)
    {
        int parent = (i - 1) / 2;
        while (i != 0 && data[i] < data[parent])
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
        int min = i;
        if (left < noe && data[left] < data[min])
            min = left;
        if (right < noe && data[right] < data[min])
            min = right;
        if (min != i)
        {
            swap(data[i], data[min]);
            heap_down(min);
        }
    }

public:
    MinHeap(int h)
    {
        height = h;
        noe = 0;
        size = pow(2, h) - 1;
        data = new T[size];
    }

    ~MinHeap()
    {
        delete[] data;
    }

    void Insert(T val)
    {
        if (noe < size)
        {
            data[noe] = val;
            int i = noe;
            noe++;
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

    T getMinimum()
    {
        if(noe>0)
        {
            return data[0];
        }
    }

    void delete_minimum()
    {
        if (noe == 0)
            return;
        swap(data[noe - 1], data[0]);
        noe--;
        heap_down(0);
    }

    int heapsize()
    {
        if(noe>0)
        {
            return noe;
        }
    }

    bool isEmpty()
    {
        return (noe==0);
    }

    void increaseKey(int i, int nval)
    {
        if (i < noe)
        {
            data[i] = nval;
            heap_down(i);
        }
    }

    void decreaseKey(int i, int nval)
    {
        if (i < noe)
        {
            data[i] = nval;
            heap_up(i);
        }
    }

    void build_from_array(T arr[],int n)
    {
        for(int i=0;i<n;i++)
        {
            data[i]=arr[i];
        }
        noe=n;
        int i=(n/2)-1;
        while(i>=0)
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
};
//#endif
int main()
{
    MinHeap<int> h(4);   
    cout << "Inserting values...\n";
    h.Insert(20);
    h.Insert(5);
    h.Insert(15);
    h.Insert(30);
    h.Insert(2);
    h.Insert(10);

    cout << "Deleting minimum...\n";
    h.delete_minimum();  
    cout << "Increasing key at index 0 to 50...\n";
    h.increaseKey(0, 50);
    cout << "Decreasing key at index 3 to 1...\n";
    h.decreaseKey(3, 1);
    cout << "Removing element at index 2...\n";
    h.remove(2);

}
