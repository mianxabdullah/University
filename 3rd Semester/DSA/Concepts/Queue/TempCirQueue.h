#ifndef circleQUEUE_H
#define circleQUEUE_H

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
template <typename T>
class Queue
{
protected:
    T *data;
    int capacity; // capacity of data array
    int noe;      // no of elements
    int front;
    int rare;

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
    void display(); // display all elements inorder
    void disp();
    void resize(int n);
};
template <typename T>
Queue<T>::Queue()
{
    noe = 0;
    front = 0;
    rare = 0;
    capacity = 10;
    data = new T[capacity];
}
template <typename T>
Queue<T>::Queue(int c)
{
    if (c > 0)
    {
        capacity = c;
        noe = 0;
        front = 0;
        rare = 0;
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
    front = 0;
    rare = noe;
    capacity = rhs.capacity;
    data = new T[capacity];
    for (int i = 0; i < noe; i++)
    {
        data[i] = rhs.data[(i + rhs.front) % rhs.capacity];
    }
}
template <typename T>
Queue<T> &Queue<T>::operator=(const Queue &rhs)
{
    if (this != &rhs)
    {
        delete[] data;
        noe = rhs.noe;
        front = 0;
        rare = noe;
        capacity = rhs.capacity;
        data = new T[capacity];
        for (int i = 0; i < noe; i++)
        {
            data[i] = rhs.data[(i + rhs.front) % rhs.capacity];
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
    if (!isFull())
    {
        data[rare] = a;
        rare = (rare + 1) % capacity;
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
    if (!isEmpty())
    {
        T r = data[front];
        front = (front + 1) % capacity;
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
        return data[front]; // it just shows or returns top value without removing it
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
        return data[(rare - 1 + capacity) % capacity];
    }
    else
    {
        throw runtime_error("Queue is empty");
    }
}
template <typename T>
void Queue<T>::display()
{
    if (!isEmpty())
    {
        for (int i = 0; i < noe; i++)
        {
            cout << data[(i + front) % capacity] << " ";
        }
        cout << endl;
    }
}
template <typename T> //easy approach
void Queue<T>::disp()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    Queue<T> temp(*this); // copy current queue using copy constructor
    while (!temp.isEmpty())
    {
        cout << temp.QueueFront() << " ";
        temp.dequeue();
    }
    cout << endl;
}
template <typename T>
void Queue<T>::resize(int nc)
{
    T *newdata = new T[nc];
    for (int i = 0; i < noe; i++)
    {
        newdata[i] = data[(i + front) % capacity];
    }
    delete[] data;
    data = newdata;
    capacity = nc;
    front = 0;
    rare = noe;
}
#endif