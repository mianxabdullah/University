#include<iostream>
#include<vector>
using namespace std;
void print_num(int n)
{
    if(n==1)
    {
        cout<<1<<endl;
        return;
    }
    cout<<n<<" ";
    print_num(n-1);
}
int factorial(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    return n*factorial(n-1);
}
int sum(int n)
{
    if(n==1)
    {
        return 1;
    }
    return n+sum(n-1);
}
int fibonacci (int n)
{
    if(n==0||n==1) 
    {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}
bool isSortArr(vector<int>arr,int n)
{
    if(n==0||n==1)
    {
        return true;
    }
    return arr[n-1]>=arr[n-2] && isSortArr(arr,n-1) ;
}
int main()
{
    print_num(10);
    cout<<factorial(5)<<endl;
    cout<<sum(5)<<endl;
    cout<<"5th fibonacci term is: "<<fibonacci(5)<<endl;
}