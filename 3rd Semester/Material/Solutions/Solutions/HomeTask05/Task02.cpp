#include<iostream>
using namespace std;

//Time complexity will be O(log₁₀n) ans space complexity will also be O(log₁₀n)
int number_of_digits(int number)
{
    if(number / 10 == 0)
    return 1;
    else
    return 1 + number_of_digits(number / 10);
}

int main()
{
    cout << number_of_digits(9);
}