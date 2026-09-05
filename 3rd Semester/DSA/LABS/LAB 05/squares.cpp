#include <iostream>
#include <cmath>
using namespace std;

int totalSquares(int k, int x, int y, int p1 = 1024, int p2 = 1024)
{
    if (k < 1)
    {
        return 0;
    }
    
    int count = 0;
    int a=p1-x;
    int b=p2-y;
    if (abs(a) <= k && abs(b) <= k)
    {
        count = 1;
    }
    if (k == 1)
        return count;
    else
    {
        return (count + totalSquares(k/2,x,y,p1-k,p2-k) //bottom left
                + totalSquares(k/2,x,y,p1-k,p2+k)    // top left
                + totalSquares(k/2,x,y,p1+k,p2-k)   //bottom right
                + totalSquares(k/2,x,y,p1+k,p2+k) ) ;   //top right
    }
}

int main()
{
    cout<<"no of squares: " << totalSquares(500, 113, 941) << endl
        <<"no of squares: " << totalSquares(300, 100, 200) << endl
        <<"no of squares: " << totalSquares(300, 1024, 1024) << endl;
}

