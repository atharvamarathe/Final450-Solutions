// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution1
{
public:
#define NIL -1
    // vector<int>adj[n];
    vector<vector<int>> res;
    void bridgeUtil(int u, bool visited[], int disc[], int low[], int parent[], vector<int> adj[], int n)
    {
        static int time = 0;

        visited[u] = true;

        disc[u] = low[u] = ++time;

        // auto i = adj[u].begin();
        for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = *i;

            if (!visited[v])
            {
                parent[v] = u;
                bridgeUtil(v, visited, disc, low, parent, adj, n);

                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u])
                    res.push_back({u, v});
            }

            else if (v != parent[u])
                low[u] = min(low[u], disc[v]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<int> adj[n];
        for (int i = 0; i < connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        bool *visited = new bool[n];
        int *disc = new int[n];
        int *low = new int[n];
        int *parent = new int[n];

        // Initialize parent and visited arrays
        for (int i = 0; i < n; i++)
        {
            parent[i] = NIL;
            visited[i] = false;
        }

        // Call the recursive helper function to find Bridges
        // in DFS tree rooted with vertex 'i'
        for (int i = 0; i < n; i++)
            if (visited[i] == false)
                bridgeUtil(i, visited, disc, low, parent, adj, n);

        return res;
    }
};

class Solution
{
public:
    void dfs(vector<int> adj[], int node, int vis[])
    {
        vis[node] = 1;
        for (auto i : adj[node])
        {
            if (!vis[i])
                dfs(adj, i, vis);
        }
    }
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d)
    {
        for (int i = 0; i < adj[c].size(); i++)
        {
            if (adj[c][i] == d)
            {
                adj[c].erase(adj[c].begin() + i);
                break;
            }
        }
        for (int j = 0; j < adj[d].size(); j++)
        {
            if (adj[d][j] == c)
            {
                adj[d].erase(adj[d].begin() + j);
                break;
            }
        }

        int vis[V] = {0};
        dfs(adj, c, vis);
        if (vis[d])
            return 0;
        return 1;

        // Code here
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

// } Driver Code Ends