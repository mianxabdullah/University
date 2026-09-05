#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
class graph
{
    int **data;
    int maxV;
    int currV;
    bool *status;

    void DFS(int v)
    {
        status[v] = true;
        cout << v << " ";
        for (int i = 1; i <= currV; i++)
        {
            if (data[v][i] > 0 && status[i] == false)
            {
                DFS(i);
            }
        }
    }
public:
    graph(int max, int curr)
    {
        maxV = max;
        currV = curr;
        data = new int *[maxV + 1];
        status = new bool[maxV + 1];
        for (int i = 0; i <= maxV; i++)
        {
            data[i] = new int[maxV + 1];
            status[i] = false;
            for (int j = 0; j <= maxV; j++)
            {
                data[i][j] = 0;
            }
        }
    }
    ~graph()
    {
        for (int i = 0; i <= maxV; i++)
            delete[] data[i];
        delete[] data;
        delete[] status;
    }
    bool addVertex(int &v)
    {
        if (currV < maxV)
        {
            currV++;
            v = currV;
            return true;
        }
        return false;
    }
    bool addEdge(int u, int v,int weight)
    {
        if (u >= 1 && u <= currV && v >= 1 && v <= currV)
        {
            data[u][v] = weight;
            data[v][u] = weight;
            return true;
        }
        return false;
    }
    bool removeEdge(int u, int v)
    {
        if (u >= 1 && u <= currV && v >= 1 && v <= currV)
        {
            data[u][v] = 0;
            data[v][u] = 0;
            return true;
        }
        return false;
    }
    // task2
    bool isEmpty()
    {
        for (int i = 1; i <= currV; i++)
        {
            for (int j = 1; j <= currV; j++)
            {
                if (data[i][j] > 0)
                    return false;
            }
        }
        return true;
    }
    bool isComplete()
    {
        if (currV <= 1)
        {
            return true;
        }
        for (int i = 1; i <= currV; i++)
        {
            for (int j = 1; j <= currV; j++)
            {
                if (i != j && data[i][j] == 0)
                    return false;
            }
        }
        return true;
    }
    void clear()
    {
        for (int i = 1; i <= currV; i++)
        {
            for (int j = 1; j <= currV; j++)
            {
                data[i][j] = 0;
            }
        }
    }
    void display()
    {
        for (int i = 1; i <= currV; i++)
        {
            for (int j = 1; j <= currV; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
    int Degree(int v)
    {
        if (v < 1 || v > currV)
        {
            return -1;
        }
        int count = 0;
        for (int i = 1; i <= currV; i++)
        {
            if (data[v][i] > 0)
            {
                count++;
            }
        }
        return count;
    }
    // task3
    void DFS()
    {
        for (int i = 1; i <= currV; i++)
        {
            status[i] = false;
        }
        int start;
        cout << "Enter starting vertex: ";
        cin >> start;
        if (start < 1 || start > currV)
            return;
        DFS(start);
        for (int i = 1; i <= currV; i++)
        {
            if (status[i] != true)
            {
                DFS(i);
            }
        }
        cout << endl;
    }
    // task4
    graph(const graph &other)
    {
        maxV = other.maxV;
        currV = other.currV;
        data = new int *[maxV + 1];
        for (int i = 0; i <= maxV; i++)
        {
            data[i] = new int[maxV + 1];
            for (int j = 0; j <= maxV; j++)
            {
                data[i][j] = other.data[i][j];
            }
        }
        status = new bool[maxV + 1];
        for (int i = 0; i <= maxV; i++)
        {
            status[i] = other.status[i];
        }
    }
    // task5
    void BFS()
    {
        for (int i = 1; i <= currV; i++)
            status[i] = false;
        int s;
        cout << "enter starting vertex: ";
        cin >> s;
        if (s < 1 || s > currV)
            return;
        queue<int> q;
        q.push(s);
        status[s] = true;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " ";
            for (int i = 1; i <= currV; i++)
            {
                if (status[i] == false && data[node][i] > 0)
                {
                    q.push(i);
                    status[i] = true;
                }
            }
        }
        for (int i = 1; i <= currV; i++)
        {
            if (status[i] == false)
            {
                status[i] = true;
                q.push(i);
                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    cout << node << " ";
                    for (int j = 1; j <= currV; j++)
                    {
                        if (data[node][j] > 0 && status[j] == false)
                        {
                            status[j] = true;
                            q.push(j);
                        }
                    }
                }
            }
        }
        cout << endl;
    }
    void primPQ()
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int *key = new int[currV + 1];
        int *parent = new int[currV + 1];
        bool *inMST = new bool[currV + 1]; 
        for (int i = 1; i <= currV; i++)
        {
            key[i] = 1e9; // infinity
            inMST[i] = false;
            parent[i] = -1;
        }
        int startNode = 1;
        key[startNode] = 0;
        pq.push({0, startNode});
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            if (inMST[u])
                continue;
            inMST[u] = true; 
            
            for (int v = 1; v <= currV; v++)
            {
                int weight = data[u][v];
                //weight > 0 to ensure there's an edge
                if (weight > 0 && inMST[v]==false && weight < key[v])
                {
                    key[v] = weight;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }
        cout << "Edge \tWeight" << endl;
        int totalWeight = 0;
        for (int i = 1; i <= currV; i++)
        {
            if (parent[i] != -1)
            {
                cout << parent[i] << " - " << i << " \t" << data[i][parent[i]] << endl;
                totalWeight += data[i][parent[i]];
            }
        }
        cout << "Total MST Weight: " << totalWeight << endl;
        delete[] key;
        delete[] parent;
        delete[] inMST;
    }

    void dijkstra(int startNode)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int *dist = new int[currV + 1];
        int *parent = new int[currV + 1];
        bool *visited = new bool[currV + 1]; 
        for (int i = 1; i <= currV; i++)
        {
            dist[i] = 1e9; // Infinity
            visited[i] = false;
            parent[i] = -1;
        }
        dist[startNode] = 0;
        pq.push({0, startNode});
        while (!pq.empty())
        {
            int u = pq.top().second;
            int d = pq.top().first; // The current distance to u
            pq.pop();
            if (visited[u])
                continue;
            visited[u] = true;
            for (int v = 1; v <= currV; v++)
            {
                int weight = data[u][v];
                if (weight > 0 && !visited[v] && dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight; 
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Vertex \t Distance from Source (" << startNode << ")" << endl;
        for (int i = 1; i <= currV; i++)
        {
            cout << i << " \t " << (dist[i] == 1e9 ? -1 : dist[i]) << endl;
        }
        delete[] dist;
        delete[] parent;
        delete[] visited;
    }
};
int main()
{
    graph g(10, 5);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(4, 5, 1);
    cout << "Adjacency Matrix:" << endl;
    g.display();

    cout << "is empty: ";
    if (g.isEmpty())
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    cout << "is complete: ";
    if (g.isComplete())
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    cout << "degree of vertex 2: " << g.Degree(2) << endl;

    cout << "BFS:" << endl;
    g.BFS();
    cout << "DFS" << endl;
    g.DFS();

    cout << endl
         << "copy const" << endl;
    graph a = g;
    g.display();
    cout << endl;
    a.display();

    g.primPQ();
}