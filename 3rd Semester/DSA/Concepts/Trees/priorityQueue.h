#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;

template <typename T>
class pQueue
{
private:
    T *data;
    int capacity;
    int size;

    T Remove_max()
    {
        if (size != 0)
        {
            T max = data[0];
            swap(data[0], data[size - 1]);
            size--;
            heapify_down(0);
            return max;
        }
        else
        {
            throw runtime_error("Queue is empty.");
        }
    }
    void heapify_up(int index)
    {
        while (index != 0 && data[index] > data[(index - 1) / 2])
        {
            swap(data[index], data[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }
    void heapify_down(int index)
    {
        int largest = index;
        int left = (2 * index) + 1;
        int right = (2 * index) + 2;
        if (left < size && data[left] > data[largest])
            largest = left;
        if (right < size && data[right] > data[largest])
            largest = right;
        if (largest != index)
        {
            swap(data[largest], data[index]);
            heapify_down(largest);
        }
    }

public:
    pQueue(int c)
    {
        capacity = c;
        size = 0;
        data = new T[capacity];
    }
    void enqueue(T val)
    {
        if (!isFull())
        {
            data[size] = val;
            size++;

            heapify_up(size - 1);
        }
        else
            throw overflow_error("Queue is full.");
    }
    T max()
    {
        if (!isEmpty())
            return data[0];
        else
            throw underflow_error("Queue is empty.");
    }
    bool isEmpty()
    {
        return size == 0;
    }
    bool isFull()
    {
        return size == capacity;
    }
    int search(T val)
    {
        if (!isEmpty())
        {
            for (int i = 0; i < size; i++)
            {
                if (data[i] == val)
                    return i;
            }
        }
        return -1;
    }
    T dequeue()
    {
        if (!isEmpty())
        {
            return (Remove_max());
        }
        else
        {
            throw runtime_error("Empty Queue");
        }
    }
    T front_data()
    {
        if (!isEmpty())
            return data[0];
        else
            throw underflow_error("Queue is empty.");
    }
    int getSize()
    {
        return size;
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
    }
    ~pQueue()
    {
        delete[] data;
    }
};

#endif