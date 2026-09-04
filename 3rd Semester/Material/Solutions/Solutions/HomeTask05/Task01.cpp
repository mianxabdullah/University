#include<iostream>
using namespace std;


//Time complexity will be o(n) ans space complexity will also be o(n)
int pow (int number, int power)
{
    if(power == 0)
    return 1;
    else
    {
        return number * pow(number , power-1);
    }
}

int main()
{
    cout << pow(2,4);
}


