#include <bits/stdc++.h>

using namespace std;

//for reference : https://www.geeksforgeeks.org/prims-algorithm-using-priority_queue-stl/

typedef pair<int, int> iPair;

void primsMST(list<pair<int, int>> adj[])
{

    //  Syntax for creating min heap implementation of prority queue
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    int src = 0;

    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty())
    {

        int u = pq.top().second;
        pq.pop();

        if (inMST[u] == true)
            continue;

        inMST[u] = true;

        for (auto i = adj[u].begin(); i != adj[u].end(); i++)
        {

            int v = (*i).first;
            int weight = (*i).second;

            if (!inMST[v] && key[v] > weight)
            {

                key[v] = weight;
                parent[v] = u;
                pq.push(make_pair(key[v], v));
            }
        }
    }

    for (int i = 1; i < V; i++)
        printf("%d - %d \n", parent[i], i);
}

int main()
{

    return 0;
}