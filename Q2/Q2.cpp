#include <bits/stdc++.h>
using namespace std;

// using Dynamic Programming
void dfs(int node, vector<int> adj[], int dp[], bool vis[])
{
    // Mark as visited
    vis[node] = true;

    // Traverse for all its children
    for (int i = 0; i < adj[node].size(); i++)
    {

        // If not visited
        if (!vis[adj[node][i]])
            dfs(adj[node][i], adj, dp, vis);

        // Store the max of the paths
        dp[node] = max(dp[node], 1 + dp[adj[node][i]]);
    }
}

// Function to add an edge
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

// Function that returns the longest path
int findLongestPath(vector<int> adj[], int N)
{
    // Dp array
    int dp[N + 1];
    memset(dp, 0, sizeof dp);

    // Visited array to know if the node
    // has been visited previously or not
    bool vis[N + 1];
    memset(vis, false, sizeof vis);

    // Call DFS for every unvisited vertex
    for (int i = 1; i <= N; i++)
    {
        if (!vis[i])
            dfs(i, adj, dp, vis);
    }

    int ans = 0;

    // Traverse and find the maximum of all dp[i]
    for (int i = 1; i <= N; i++)
    {
        ans = max(ans, dp[i]);
    }
    return ans;
}

// Driver Code
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N,M;
    cin >> N >> M;
    vector<int> adj[N + 1];
    int u, v;
    cin >> u >> v;
    for (int i = 0; i < M;i++){
    addEdge(adj, u, v);
    }
    
    cout << findLongestPath(adj, N);
    return 0;
}
