// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


bool isSafe(int node, bool graph[101][101], int m, int V, int color[], int col) {
for (int i = 0; i < V; i++) {
if (i != node && graph[i][node] == 1 && color[i] == col)
return false;
}
return true;
}

bool m_coloring(int node, bool graph[101][101], int m, int V, int color[]) {
if (node == V)
return true;


for (int j = 1; j <= m; j++) {
if (isSafe(node, graph, m, V, color, j)) {
color[node] = j;
if (m_coloring(node + 1, graph, m, V, color))
return true;
color[node] = 0;
}
}

return false;
}


bool graphColoring(bool graph[101][101], int m, int V)
{
int color[V] = {0};
if ( m_coloring(0, graph, m, V, color))
return true;
return false;

}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends