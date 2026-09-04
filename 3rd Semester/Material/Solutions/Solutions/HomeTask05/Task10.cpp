#include<iostream>
using namespace std;

void towerOfHanoi(int n, char s, char d, char h)
{
    if(n == 1)
     cout << "Move disk 1 from " << s << " to " << d << endl;

    else
    {
        towerOfHanoi(n-1 , s , h , d);
        cout << "Move disk "<< n <<" from " << s << " to " << d << endl;
        towerOfHanoi(n-1 , h , d , s);
    }
}

int main()
{
    towerOfHanoi(3, 'A' , 'C' , 'B');
}