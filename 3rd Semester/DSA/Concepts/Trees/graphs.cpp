#include <iostream>
#include <queue>
#include <stack>
using namespace std;
class graph
{
    int **data;
    int V;
    bool *status;

public:
    graph(int v)
    {
        V = v;
        data = new int *[V];
        status = new bool[V];
        for (int i = 0; i < V; i++)
        {
            data[i] = new int[V];
            status[i] = false;
        }
    }
    void addEdge(int v, int u)
    {
        if (v < V && u < V)
        {
            data[v][u] = 1;
            data[u][v] = 1;
        }
    }
    void BFS(int s)
    {
        queue<int> q;
        q.push(s);
        status[s] = true;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " ";
            for (int i = 0; i < V; i++)
            {
                if (status[i] == false && data[node][i] == 1)
                {
                    q.push(i);
                    status[i] = true;
                }
            }
        }
    }
    void resetStatus()
    {
        for (int i = 0; i < V; i++)
            status[i] = false;
    }

    void DFS(int s)
    {
        resetStatus();
        stack<int> st;
        st.push(s);
        status[s] = true;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            cout << node << " ";
            for (int i = 0; i < V; i++)
            {
                if (status[i] == false && data[node][i] == 1)
                {
                    st.push(i);
                    status[i] = true;
                }
            }
        }
    }

    ~graph()
    {
        for (int i = 0; i < V; i++)
            delete[] data[i];
        delete[] data;
        delete[] status;
    }
};