#include "TempStack.h"
#include <iostream>
using namespace std;

struct Pair
{
    int i;
    int j;
};
bool findPathh(int a[5][5], Pair cur, Pair d, int r, int c)
{
    if (cur.i == d.i && cur.j == d.j)
    {
        cout<<"("<<cur.i<<","<<cur.j<<")";
        return true;
    }
    a[cur.i][cur.j] = 5;
    if (cur.j + 1 < c && a[cur.i][cur.j + 1] == 0) // right
    {
        a[cur.i][cur.j] = 5;
        cur.j += 1;
        if(findPathh(a,cur,d,r,c))
        {
            cout<<"("<<cur.i<<","<<cur.j<<")";
            return true;
        }
    }
    if (cur.j - 1 >= 0 && a[cur.i][cur.j - 1] == 0) // left
    {
        a[cur.i][cur.j] = 5;
        cur.j -= 1;
        if(findPathh(a,cur,d,r,c))
        {
            cout<<"("<<cur.i<<","<<cur.j<<")";
            return true;
        }
    }
    if (cur.i + 1 < r && a[cur.i + 1][cur.j] == 0) // down
    {
        a[cur.i][cur.j] = 5;
        cur.i += 1;
        if(findPathh(a,cur,d,r,c))
        {
            cout<<"("<<cur.i<<","<<cur.j<<")";
            return true;
        }
    }
    if (cur.i - 1 >= 0 && a[cur.i - 1][cur.j] == 0)
    {
        a[cur.i][cur.j] = 5;
        cur.i -= 1;
        if(findPathh(a,cur,d,r,c))
        {
            cout<<"("<<cur.i<<","<<cur.j<<")";
            return true;
        }
    }
        a[cur.i][cur.j] = 0;
        return false;
}

int main()
{
    int arr[5][5] = {{0, 0, 0, 0, 0}, 
                    {1, 0, 1, 1, 1}, 
                    {0, 0, 0, 0, 0}, 
                    {0, 0, 1, 0, 0}, 
                    {0, 1, 1, 0, 0}};
    Pair st;
    st.i = 0;
    st.j = 0;
    Pair end;
    end.i = 4;
    end.j = 3;
    cout << "Path: "; 
    if (findPathh(arr, st, end, 5, 5)) cout << "\nPath Found\n";    
    else cout << "No Path Found\n";
}