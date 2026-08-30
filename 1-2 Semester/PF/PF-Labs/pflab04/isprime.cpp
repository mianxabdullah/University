#include<iostream>
using namespace std;
bool isprime(int n)
{
   bool r = true;
   int i = 2;
   while (i < n)
   {
     if (n % i == 0)
     {
       r = false;
     }
     i = i + 1;
   }
   return r;
}
int main()
{
    for(int a=2;a<=10000;a++)
    {
        if(isprime(a))
        {
            cout<<a<<endl;
        }
    }
    return 0;
}