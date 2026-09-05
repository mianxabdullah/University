#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int vertex;
    int weight; 
    Node *next;
    Node(int v, int w = 1)
    {
        vertex = v;
        weight = w;
        next = nullptr;
    }
};
class graph
{
    Node **data;
    int maxV;
    int currV;
    bool *status;

    void DFS(int v)
    {
        status[v] = true;
        cout << v << " ";
        Node *curr = data[v];
        while (curr != nullptr)
        {
            if (status[curr->vertex] == false)
            {
                DFS(curr->vertex);
            }
            curr = curr->next;
        }
    }
    void insertSorted(int u, int v, int w)
    {
        Node *newNode = new Node(v, w);
        if (data[u] == nullptr || data[u]->vertex > v)
        {
            newNode->next = data[u]; //INSERT AT HEAD
            data[u] = newNode;
        }
        else
        {
            Node *temp = data[u];
            while (temp->next != nullptr && temp->next->vertex < v)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    bool deleteFromList(int from, int to)
    {
        Node *temp = data[from];
        Node *prev = nullptr;
        while (temp != nullptr)
        {
            if (temp->vertex == to)
            {
                if (prev == nullptr)
                {
                    data[from] = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }
                delete temp;
                return true;
            }
            prev = temp;
            temp = temp->next;
        }
        return false;
    }

public:
    graph(int max, int curr)
    {
        maxV = max;
        currV = curr;
        data = new Node *[maxV + 1];
        status = new bool[maxV + 1];
        for (int i = 0; i <= maxV; i++)
        {
            data[i] = nullptr;
            status[i] = false;
        }
    }
    ~graph()
    {
        clear();
        delete[] data;
        delete[] status;
    }
    bool addVertex(int &v)
    {
        if (currV < maxV)
        {
            currV++;
            v = currV;
            data[v] = nullptr;
            return true;
        }
        return false;
    }
    bool addEdge(int u, int v, int w)
    {
        if (u >= 1 && u <= currV && v >= 1 && v <= currV)
        {
            insertSorted(u, v, w);
            insertSorted(v, u, w);
            return true;
        }
        return false;
    }
    bool removeEdge(int u, int v)
    {
        if (u >= 1 && u <= currV && v >= 1 && v <= currV)
        {
            bool deletedU = deleteFromList(u, v);
            bool deletedV = deleteFromList(v, u);
            return (deletedU && deletedV);
        }
        return false;
    }
    // task2
    bool isEmpty()
    {
        for (int i = 1; i <= currV; i++)
        {
            if (data[i] != nullptr)
                return false;
        }
        return true;
    }
    bool isComplete()
    {
        if (currV <= 1)
            return true;
        for (int i = 1; i <= currV; i++)
        {
            if (Degree(i) != currV - 1)
                return false;
        }
        return true;
    }
    void clear()
    {
        for (int i = 0; i <= maxV; i++)
        {
            Node *temp = data[i];
            while (temp != nullptr)
            {
                Node *rm = temp;
                temp = temp->next;
                delete rm;
            }
            data[i] = nullptr;
        }
    }
    void display()
    {
        for (int i = 1; i <= currV; i++)
        {
            cout << i << ": ";
            Node *temp = data[i];
            while (temp != nullptr)
            {
                cout << "-> " << temp->vertex << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    int Degree(int v)
    {
        if (v < 1 || v > currV)
            return -1;
        int count = 0;
        Node *temp = data[v];
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    // task3
    void DFS()
    {
        for (int i = 1; i <= currV; i++)
            status[i] = false;
        int s;
        cout << "Enter starting vertex: ";
        cin >> s;
        if (s < 1 || s > currV)
            return;
        DFS(s);
        for (int i = 1; i <= currV; i++)
        {
            if (status[i] == false)
                DFS(i);
        }
        cout << endl;
    }
    // task4
    graph(const graph &other)
    {
        maxV = other.maxV;
        currV = other.currV;
        data = new Node *[maxV + 1];
        status = new bool[maxV + 1];
        for (int i = 0; i <= maxV; i++)
        {
            data[i] = nullptr;
            status[i] = other.status[i];
            Node *curr = other.data[i];
            Node *last = nullptr;
            while (curr != nullptr)
            {
                Node *newNode = new Node(curr->vertex);
                if (data[i] == nullptr)
                    data[i] = newNode;
                else
                    last->next = newNode;
                last = newNode;
                curr = curr->next;
            }
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
        status[s] = true;
        q.push(s);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " ";

            Node *temp = data[node];
            while (temp != nullptr)
            {
                if (status[temp->vertex] == false)
                {
                    status[temp->vertex] = true;
                    q.push(temp->vertex);
                }
                temp = temp->next;
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

                    Node *temp = data[node];
                    while (temp != nullptr)
                    {
                        if (status[temp->vertex] == false)
                        {
                            status[temp->vertex] = true;
                            q.push(temp->vertex);
                        }
                        temp = temp->next;
                    }
                }
            }
        }
        cout << endl;
    }
    typedef pair<int, int> pii;
    void primPQ(int startNode)
    {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        int *key = new int[currV + 1];
        int *parent = new int[currV + 1];
        bool *inMST = new bool[currV + 1];

        for (int i = 1; i <= currV; i++)
        {
            key[i] = 1e9;
            inMST[i] = false;
            parent[i] = -1;
        }

        key[startNode] = 0;
        pq.push({0, startNode});

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u])
                continue;
            inMST[u] = true;

            // TRAVERSING THE LIST
            Node *temp = data[u];
            while (temp != nullptr)
            {
                int v = temp->vertex;
                int weight = temp->weight;

                if (!inMST[v] && weight < key[v])
                {
                    key[v] = weight;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
                temp = temp->next; // Move to next neighbor
            }
        }

        cout << "\nMST Edges (Prim's List):\n";
        for (int i = 1; i <= currV; i++)
            if (parent[i] != -1)
                cout << parent[i] << " - " << i << endl;

        delete[] key;
        delete[] parent;
        delete[] inMST;
    }

    /* --- DIJKSTRA'S FOR LIST --- */
    void dijkstraPQ(int startNode)
    {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        int *dist = new int[currV + 1];
        bool *visited = new bool[currV + 1];

        for (int i = 1; i <= currV; i++)
        {
            dist[i] = 1e9;
            visited[i] = false;
        }

        dist[startNode] = 0;
        pq.push({0, startNode});

        while (!pq.empty())
        {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (visited[u]) continue;
            visited[u] = true;

            Node *temp = data[u];
            while (temp != nullptr)
            {
                int v = temp->vertex;
                int weight = temp->weight;

                if (dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
                temp = temp->next; 
            }
        }

        cout << "\nShortest Distances (Dijkstra List):\n";
        for (int i = 1; i <= currV; i++)
            cout << "To " << i << ": " << dist[i] << endl;

        delete[] dist;
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
}