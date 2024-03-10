#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> mp;

void topoSort(unordered_map<int, vector<int>> &mp, int V, bool vis[], int ind[], int SV)
{
    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (ind[i] == 0)
        {
            if (!vis[i])
            {
                vis[i] = 1;
                q.push(i);
            }
        }
    }

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        vector<int> temp = mp[v];
        for (auto it = temp.begin(); it != temp.end(); ++it)
        {
            if (!vis[*it])
            {
                ind[*it]--;
                if (ind[*it] == 0)
                {
                    q.push(*it);
                    vis[*it] = 1;
                }
            }
        }
    }
}

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int V, E;
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        mp[u].push_back(v);
    }

    bool vis[V] = {0};
    int ind[V] = {0};

    for (auto it1 : mp)
    {
        for (auto it2 = mp[it1.first].begin(); it2 != mp[it1.first].end(); ++it2)
        {
            ind[*it2]++;
        }
    }

    topoSort(mp, V, vis, ind, 0);
    return 0;
}