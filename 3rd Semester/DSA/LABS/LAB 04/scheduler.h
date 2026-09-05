#ifndef scheduler_H
#define scheduler_H
#include "TempCirQueue.h"
#include "process.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Scheduler
{
private:
    Queue<Process> q;
    int timeQuantum;

public:
    Scheduler(Process arr[], int len, int tq)
    {
        timeQuantum = tq;
        for (int i = 0; i < len; i++)
        {
            q.enqueue(arr[i]);
        }
    }
    void assignProcessor()
    {
        while (!q.isEmpty())
        {
            Process p = q.dequeue();
            int exetime = p.getExecutionTime();
            int runtime = (exetime > timeQuantum) ? timeQuantum : exetime;
            cout << "Executing process " << p.getName()
                 << " for " << runtime << " units" << endl;
            exetime-=runtime;
            p.setExecutionTime(exetime);
            if (exetime > 0)
            {
                q.enqueue(p);
            }
        }
        cout << "All processes have finished execution" << endl;
    }
};
#endif
