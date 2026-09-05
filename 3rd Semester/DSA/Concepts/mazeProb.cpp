#include "TempStack.h"
#include<iostream>
using namespace std;

struct Pair
{
    int i;
    int j;
};
void findPath(int a[5][5],Pair s,Pair d,int  r,int c)
{
    Stack<Pair> sa(r*c);
    sa.push(s);
    while(!sa.isEmpty())
    {
        Pair cur=sa.StackTop();
        if(cur.i==d.i && cur.j==d.j)
        {
            cout<<"Path Found"<<endl;
            return ;
        }
        else if(cur.j+1<c && a[cur.i][cur.j+1]==0 ) //right
        {
            a[cur.i][cur.j]=5;
            cur.j+=1;
            sa.push(cur);
        }
        else if(cur.j-1>=0 && a[cur.i][cur.j-1]==0 ) //left
        {
            a[cur.i][cur.j]=5;
            cur.j-=1;
            sa.push(cur);
        }
        else if(cur.i+1<r && a[cur.i+1][cur.j]==0 ) //down
        {
            a[cur.i][cur.j]=5;
            cur.i+=1;
            sa.push(cur);
        }
        else if(cur.i-1>=0 && a[cur.i-1][cur.j]==0 )
        {
            a[cur.i][cur.j]=5;
            cur.i-=1;
            sa.push(cur);
        }
        else
        {
            a[cur.i][cur.j] = 5;
            sa.pop();
        }
    }
    cout<<"No Path Found"<<endl;

}
int main()
{
    int arr[5][5]={{0,0,0,0,0},{1,0,1,1,1},{0,0,0,0,0},{0,0,1,0,0},{0,1,1,0,0}};
    Pair st;
    st.i=0;
    st.j=0;
    Pair end;
    end.i=4;
    end.j=3;
    findPath(arr,st,end,5,5);
}