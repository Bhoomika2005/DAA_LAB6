#include <bits/stdc++.h>
using namespace std;

int dfs(int u, int p, vector<vector<int>> &adj, vector<int> &disc, vector<int> &low, int &time, vector<bool> &ap, vector<pair<int, int>> &bridges)
{
    int children = 0;
    disc[u] = low[u] = time++;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        if (disc[v] == 0)
        {
            children++;
            dfs(v, u, adj, disc, low, time, ap, bridges);
            if (disc[u] <= low[v])
                ap[u] = true;
            if (disc[u] < low[v])
                bridges.emplace_back(u, v);
            low[u] = min(low[u], low[v]);
        }
        else
        {
            low[u] = min(low[u], disc[v]);
        }
    }
    return children;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V + 1);
    vector<int> disc(V + 1);
    vector<int> low(V + 1);
    vector<bool> ap(V + 1);
    vector<pair<int, int>> bridges;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int time = 0;
    for (int i = 1; i <= V; i++)
    {
        if (disc[i] == 0)
        {
            if (dfs(i, 0, adj, disc, low, time, ap, bridges) > 1)
                ap[i] = true;
        }
    }
    cout << "Articulation Points:";
    for (int i = 1; i <= V; i++)
    {
        if (ap[i])
            cout << i << " ";
    }
    cout << endl;
    cout << "Bridges:";
    for (auto bridge : bridges)
    {
        cout << "{" << bridge.first << "," << bridge.second << "} ";
    }
}