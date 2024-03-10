#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

    // Used by isCyclic()
    bool isCyclicUtil(int v, bool visited[], bool *rs);

public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isCyclic();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    // Add w to v’s list.
    adj[v].push_back(w);
}

// DFS function to find if a cycle exists
bool Graph::isCyclicUtil(int v, bool visited[],
                         bool *recStack)
{
    if (visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;

        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if (!visited[*i] && isCyclicUtil(*i, visited, recStack))
                return true;
            else if (recStack[*i])
                return true;
        }
    }

    recStack[v] = false;
    return false;
}

// Returns true if the graph contains a cycle, else false
bool Graph::isCyclic()
{
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < V; i++)
        if (!visited[i] && isCyclicUtil(i, visited, recStack))
            return true;

    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int V, E;
    cin >> V >> E;
    Graph g(V);
    int u, v;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v;
        g.addEdge(u, v);
    }

    if (g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}
