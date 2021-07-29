#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


typedef vector<int> disjoint_set;



int find(disjoint_set Set,int x) {

    if(Set[x] < 0)
        return x;
    return Set[x] = find(Set,Set[x]);
}

//Assuming that arguments to union are the roots of the two disjoint sets
// and they do not belong to the same set
void union_set(disjoint_set Set,int x,int y) {

    if(Set[x] < Set[y]) {
        Set[x] = Set[x] + Set[y];
        Set[y] = x;
    }

    else {
        Set[y] = Set[y] + Set[x];
        Set[x] = y;
    }
}

//Using adjecency matrix
void kruskalsMST(Graph *g) {
    disjoint_set Set;

    vector<vector<int>> edges(3,vector<int>(g->E,0));
    vector<vector<int>> MST(3,vector<int>(g->E,0));
    vector<int> included(g->E,0);

    int m= 0;
    for(int i = 0;i<V;i++) {
        for (int j = i+1;j<V;j++) {
            if(g->arr[i][j] != INT_MIN) {
                edges[0][m] = i;
                edges[1][m] = j;
                edges[2][m] = g-> arr[i][j];
                m+=1;
            }
        }
    }
    
    while(i<V-1) {
        int min = INT_MIN;
        int u,v,k;

        // for-loop for finding min edge. Actually can be sorted first. 
        for(int j = 0;j<g->E;j++) {
            if(!included[j] && edges[2][j] < min) {
                min = edges[2][j];
                u = edges[0][j];
                v = edges[1][j];
                k = j;
            }
        }

        if(find(Set,u) != find(Set,v)) {
            MST[0][i] = u;
            MST[1][i] = v;
            MST[2][i] = edges[2][k];
            union_set(Set,find(Set,u),find(Set,v));
            i++;
        }
        included[k] = 1;
    }
}
