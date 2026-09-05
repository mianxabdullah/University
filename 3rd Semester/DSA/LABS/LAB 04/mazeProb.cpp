#include "TempStack.h"
#include<iostream>
using namespace std;

struct Pair
{
    int i;
    int j;
};
void solve_maze(char a[6][6],Pair s,Pair d,int  r,int c)
{
    string abc=" ";
    Stack<Pair> sa(r*c);
    sa.push(s);
    while(!sa.isEmpty())
    {
        Pair cur=sa.StackTop();
        if(cur.i==d.i && cur.j==d.j)
        {
            cout<<"solved"<<endl;
            Stack<Pair>opp(r*c);
            while(!sa.isEmpty())
            {  
                Pair res=sa.pop();
                opp.push(res);
            }
            while(!opp.isEmpty())
            { 
                 Pair r=opp.pop();
                 cout<<"("<<r.i<<","<<r.j<<")";
            }
            return ;
        }
        else if(cur.j+1<c && (a[cur.i][cur.j+1]==abc[0] || a[cur.i][cur.j+1]=='T')) //right
        {
            a[cur.i][cur.j]='P';
            cur.j+=1;
            sa.push(cur);
        }
        else if(cur.j-1>=0 && (a[cur.i][cur.j-1]==abc[0]|| a[cur.i][cur.j-1]=='T') ) //left
        {
            a[cur.i][cur.j]='P';
            cur.j-=1;
            sa.push(cur);
        }
        else if(cur.i+1<r &&( a[cur.i+1][cur.j]==abc[0] || a[cur.i+1][cur.j]=='T')) //down
        {
            a[cur.i][cur.j]='P';
            cur.i+=1;
            sa.push(cur);
        }
        else if(cur.i-1>=0 && (a[cur.i-1][cur.j]==abc[0] || a[cur.i-1][cur.j]=='T') )//up
        {
            a[cur.i][cur.j]='P';
            cur.i-=1;
            sa.push(cur);
        }
        else
        {
            a[cur.i][cur.j] = 'P';
            sa.pop();
        }
    }
    cout<<endl<<"Unsolved"<<endl;
}
int main()
{
    char maze1[6][6] = { 
        {' ', '*', ' ', '*', ' ', ' '}, 
        {' ', '*', ' ', '*', ' ', ' '}, 
        {'P', ' ', ' ', ' ', '*', ' '}, 
        {'*', ' ', '*', '*', '*', ' '}, 
        {' ', ' ', ' ', ' ', '*', 'T'}, 
        {'*', ' ', ' ', ' ', ' ', ' '} 
    };

    Pair st;
    st.i=2;
    st.j=0;
    Pair end;
    end.i=4;
    end.j=5;
    solve_maze(maze1,st,end,6,6);

    char maze2[6][6] = { 
  {' ', '*', ' ', '*', ' ', ' '}, 
  {' ', '*', ' ', '*', ' ', ' '}, 
  {'P', ' ', ' ', ' ', '*', ' '}, 
  {'*', '*', '*', ' ', '*', ' '}, 
  {' ', ' ', ' ', ' ', '*', 'T'}, 
  {'*', ' ', ' ', ' ', ' ', ' '} 
     };
    solve_maze(maze2,st,end,6,6);
}