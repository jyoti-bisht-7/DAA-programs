#include <bits/stdc++.h>
using namespace std;

// Check if an undirected graph is Bipartite using DFS

void addEdge(vector<vector<int> > &adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool DFS(int node, int col, vector<int> &color, vector<vector<int> > &adj) {
    color[node] = col;

    for (int it : adj[node]) {
        if (color[it] == -1) {
            if (!DFS(nit, !col, color, adj))
                return false;
        } 
		else if (color[it] == col) {
            return false;
        }
    }

    return true;
}

int main() {
    int n, e;
    cout << "Enter no.of vertices and edges: ";
    cin >> n >> e;

    vector<vector<int> > adj(n);
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    vector<int> color(n, -1);
    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {
            if (!DFS(i, 0, color, adj)) {
                cout << "Not Bipartite.\n";
                return 0;
            }
        }
    }

    cout << "Yes Bipartite.\n";
    return 0;
}

