#include<iostream>
using namespace std;

int min_element(int *arr , int n)
{
    if(n == 0)
    return arr[0];
    else
    {
        int mini = min_element(arr , n - 1);
        return min(arr[n-1] , mini);
    }
}

int main()
{
    int *arr = new int[7];
    for(int i = 0; i < 7; i++)
    {
        arr[i] = i*2;
    }
    arr[0] = -8;
    cout << min_element(arr , 7);
}