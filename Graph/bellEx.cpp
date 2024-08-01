#include <bits/stdc++.h>
using namespace std;

// Function to add an edge to the adjacency list
void addEdge(vector<vector<pair<int, int>>>& adjList, int u, int v, int weight) {
    adjList[u].emplace_back(v, weight);
    adjList[v].emplace_back(u, weight);
}

// Bellman-Ford algorithm implementation
vector<int> bellmanFord(vector<vector<pair<int, int>>>& adjList, int V, int src) {
    // Initialize distances to all nodes as infinite except source
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relaxation phase: iterate |V| - 1 times
    for (int i = 0; i < V - 1; ++i) {
        // Iterate through all edges and update distances
        for (int u = 0; u < V; ++u) {
            for (const auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                // Relaxation step: update distance if shorter path found
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    // Check for negative weight cycles
    for (int u = 0; u < V; ++u) {
        for (const auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            // If a shorter path still exists, negative cycle detected
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                cout << "Graph contains negative weight cycle." << endl;
                exit(0);
            }
        }
    }

    return dist; // Return the computed distances
}

int main() {
    int V = 9;
    vector<vector<pair<int, int>>> adjList(V); // Adjacency list representation

    // Adding edges to the graph
    addEdge(adjList, 0, 1, 4);
    // ... (similar lines for other edges)

    int src = 0; // Source node for Bellman-Ford algorithm
    vector<int> dist = bellmanFord(adjList, V, src); // Compute shortest distances

    // Print the computed distances
    cout << "Output:" << endl;
    for (int i = 0; i < V; ++i) {
        if (dist[i] == INT_MAX) {
            cout << "0 to " << i << " is unreachable" << endl;
        } else {
            cout << "0 to " << i << " is " << dist[i] << endl;
        }
    }

    return 0;
}
