#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int> >& adj, int u, int v, int w) {
    adj[u][v] = w;
}

void BellmanFord(vector<vector<int> >& adj, int src) {
    int n = adj.size();

    // Initialize distances and predecessors
    vector<int> dist(n, 1e9);
    vector<int> pii(n, -1);
    dist[src] = 0;

    // Relax all edges 
    for (int k = 0; k < n - 1; ++k) {
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                if (adj[u][v] != 0 && dist[u] != 1e9 && dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                    pii[v] = u;
                }
            }
        }
    }

    // Check for negative weighted cycles
    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            if (adj[u][v] != 0 && dist[u] != 1e9 && dist[u] + adj[u][v] < dist[v]) {
                cout << "Graph contains a negative weight cycle.\n";
                return;
            }
        }
    }

    // Print paths and distances
    cout << "The distances and paths from Akshay's house to friends' houses are:\n";
    for (int i = 0; i < n; i++) {
        if (i != src) {
            cout << i << "\n";
            if (dist[i] == 1e9) {
                cout << "No path\n";
                continue;
            }
            int j = i;
            cout << j;
            while (j != src) {
                cout << "<-" << pii[j];
                j = pii[j];
            }
            cout << " Distance: " << dist[i] << endl;
        }
    }
}

int main() {
    int n, e;
    cout << "Enter no.of vertices and edges: ";
    cin >> n >> e;
    vector<vector<int> > adj(n, vector<int>(n, 0));
    cout << "Enter edges and weights (u v w): ";
    int u, v, w;
    for (int i = 0; i < e; i++) {
        cin >> u >> v >> w;
        addEdge(adj, u, v, w);
    }
    int src;
    cout << "Enter source node: ";
    cin >> src;
    BellmanFord(adj, src);
    return 0;
}
