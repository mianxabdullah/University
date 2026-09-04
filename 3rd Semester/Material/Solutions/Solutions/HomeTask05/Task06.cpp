#include<iostream>
using namespace std;

int squares_sum(int n)
{
    if(n == 1 || n == 0)
    return n;
    else
    {
        //int temp = n*n;
        return (n*n) + squares_sum(n-1);
    }
}

int main()
{
    cout << squares_sum(3);
}