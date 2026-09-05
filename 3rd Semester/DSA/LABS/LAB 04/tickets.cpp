#include "TempCirQueue.h"
struct Pair
{
    int i, j; //i=data/no of tickets remaining ,j= its index
};
int time(int arr[], int s, int k)
{
    int count = 0;
    Queue<Pair> q(s);
    for (int i = 0; i < s; i++)
    {
        Pair a;
        a.i = arr[i];
        a.j = i;
        q.enqueue(a);
    }

    while (!q.isEmpty())
    {
        Pair curr = q.dequeue();
        curr.i--; 
        count++;  
        if (curr.i > 0)
        {
            q.enqueue(curr);
        }
        if (curr.j == k && curr.i == 0)
        {
            break;
        }
    }

    return count;
}
int main()
{
    int a[4] = {3, 5, 3, 7};
    int k = 2;
    cout << time(a, 4, k);
}