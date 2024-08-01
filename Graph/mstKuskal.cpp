#include <bits/stdc++.h>
using namespace std;

// Function to perform find operation with path compression
int find(vector<int>& parent, int v) {
    if (parent[v] == v)
        return v;
    return parent[v] = find(parent, parent[v]);
}

// Function to perform union operation with rank optimization
void unionSets(vector<int>& parent, vector<int>& rank, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);

    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;

        if (rank[a] == rank[b])
            rank[a]++;
    }
}

int main() {
    int V = 4;
    vector<vector<pair<int, int>>> adjList(V);

    // Function to add an edge to the graph
    auto addEdge = [&adjList](int u, int v, int weight) {
        adjList[u].push_back(make_pair(v, weight));
        adjList[v].push_back(make_pair(u, weight)); // For an undirected graph, add the reverse edge as well.
    };

    // Adding edges to the graph
    addEdge(0, 1, 10);
    addEdge(2, 0, 6);
    addEdge(0, 3, 5);
    addEdge(1, 3, 15);
    addEdge(2, 3, 4);

    vector<pair<int, pair<int, int>>> edges; // (weight, (u, v))

    for (int u = 0; u < V; ++u) {
        for (auto edge : adjList[u]) {
            int v = edge.first;
            int weight = edge.second;
            edges.push_back({weight, {u, v}});
        }
    }

    sort(edges.begin(), edges.end());

    vector<int> parent(V + 1);
    vector<int> rank(V + 1, 0);
    for (int i = 0; i <= V; i++) parent[i] = i;

    int totalWeight = 0;

    for (auto edge : edges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if (find(parent, u) != find(parent, v)) {
            unionSets(parent, rank, u, v);
            totalWeight += weight;
            cout << "Edge: " << u << " -- " << v << " : " << weight << endl;
        }
    }

    cout << "Total MST Weight: " << totalWeight << endl;

    return 0;
}
