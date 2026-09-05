
#include<iostream>
using namespace std;
int countWays(int stairs)
{
    if(stairs==0 || stairs==1)
        return 1;
    else
    {
        return countWays(stairs-1)+countWays(stairs-2);
    }
}
int main()
{
    int no_of_stairs=5;
    cout<<"Total no of ways to climb a stair of steps "<<no_of_stairs
    <<" are: "<<countWays(no_of_stairs);
}