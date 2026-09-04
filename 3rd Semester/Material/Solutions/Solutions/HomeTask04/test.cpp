#include<iostream>
using namespace std;


int min_e(int *arr , int size)
{
    if(size == 1)
    {
        return arr[0];
    }
    
   int curr_element = arr[size - 1];
   int next_element = min_e(arr , size - 1);
   return min(curr_element , next_element);
}

int main()
{
    int *arr = new int[7];
    for(int i = 0; i < 7; i++)
    {
        arr[i] = i*2;
    }
    arr[0] = -8;
    cout << min_e(arr , 7);
}