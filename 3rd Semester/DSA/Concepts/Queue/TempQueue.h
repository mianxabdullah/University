#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include<string>
#include <cmath>
using namespace std;
template <typename T>
class Queue
{
protected:
    T *data;
    int capacity; // capacity of data array
    int noe;      // no of elements
public:
    Queue();
    Queue(int c);
    Queue(const Queue &rhs);
    Queue &operator=(const Queue &rhs);
    ~Queue();
    void enqueue(T a);
    T dequeue();
    bool isFull();
    bool isEmpty();
    int getNoE();
    T QueueFront();
    T QueueRare();
};
    template <typename T>
    Queue<T>::Queue()
    {
        noe=0;
        capacity=10;
        data=new T[capacity];
    }
    template <typename T>
    Queue<T>::Queue(int c)
    {
        if (c > 0)
        {
            capacity = c;
            noe = 0;
            data = new T[c];
            for (int i = 0; i < c; i++)
            {
                data[i] = T();
            }
        }
        else
        {
            throw invalid_argument("Capacity must be positive");
        }
    }
    template <typename T>
    Queue<T>::Queue(const Queue &rhs)
    {
        noe = rhs.noe;
        capacity = rhs.capacity;
        data = new T[capacity];
        for (int i = 0; i < noe; i++)
        {
            data[i] = rhs.data[i];
        }
    }
    template <typename T>
    Queue<T>& Queue<T>::operator=(const Queue &rhs)
    {
        if (this != &rhs)
        {
            delete[] data;
            noe = rhs.noe;
            capacity = rhs.capacity;
            data = new T[capacity];
            for (int i = 0; i < noe; i++)
            {
                data[i] = rhs.data[i];
            }
        }
        return *this;
    }
    template <typename T>
    Queue<T>::~Queue()
    {
        delete[] data;
    }
    template <typename T>
    void Queue<T>::enqueue(T a)
    {
        if (noe != capacity)
        {
            data[noe] = a;
            noe++;
        }
        else 
        {
            throw runtime_error("Queue is full");
        }
    }
    template <typename T>
    T Queue<T>::dequeue()
    {
        
        if (noe > 0)
        {
            T r=data[0];
            for(int i=1;i<noe;i++) //after removing from 0 index shift all elements one index behind
            {
                data[i-1]=data[i];
            }
            noe--;
            return r;
        }
        else
        {
            throw runtime_error("Queue is empty");
        }
    }
    template <typename T>
    bool Queue<T>::isFull()
    {
        if (noe == capacity)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    template <typename T>
    bool Queue<T>::isEmpty()
    {
        if (noe == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    template <typename T>
    int Queue<T>::getNoE()
    {
        return noe;
    }
    template <typename T>
    T Queue<T>::QueueFront()
    {
        if (noe != 0)
        {
            return data[0]; // it just shows or returns top value without removing it
        }
        else
        {
            throw runtime_error("Queue is empty");
        }
    }
        template <typename T>
    T Queue<T>::QueueRare()
    {
        if (noe != 0)
        {
            return data[noe-1]; 
        }
        else
        {
            throw runtime_error("Queue is empty");
        }
    }
#endif