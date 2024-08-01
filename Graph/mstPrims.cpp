#include <bits/stdc++.h>
using namespace std;

void primAlgorithm(vector<vector<pair<int, int>>>& adjList, int V) {
    vector<bool> vis(V, false);  // To track visited vertices
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // Min heap for storing vertices

    pq.push(make_pair(0, 0));  // Pushing the starting vertex (vertex 0) with weight 0
    int cost = 0;  // To store the cost of the Minimum Spanning Tree

    // Prim's Algorithm
    while (!pq.empty()) {
        pair<int, int> curr = pq.top();  // Get the vertex with the minimum weight
        pq.pop();
        int vertex = curr.second;  // Extract the vertex
        int weight = curr.first;   // Extract the weight

        if (!vis[vertex]) {  // If the vertex hasn't been visited
            vis[vertex] = true;  // Mark the vertex as visited
            cost += weight;  // Add the weight to the cost of MST

            for (const auto& neighbor : adjList[vertex]) {
                int dest = neighbor.first;  // Get the neighbor's vertex
                int wt = neighbor.second;   // Get the weight of the edge

                if (!vis[dest]) {  // If the neighbor hasn't been visited
                    pq.push(make_pair(wt, dest));  // Push the neighbor into the priority queue
                }
            }
        }
    }

    cout << "Minimum Spanning Tree Cost: " << cost << endl;  // Print the cost of the MST
}

int main() {
    int V = 4;  // Number of vertices
    vector<vector<pair<int, int>>> adjList(V);  // Adjacency list to store graph

    // Function to add an edge to the graph
    auto addEdge = [&adjList](int u, int v, int weight) {
        adjList[u].push_back(make_pair(v, weight));
        adjList[v].push_back(make_pair(u, weight)); // For an undirected graph, add the reverse edge as well.
    };

    // Adding edges to the graph
    addEdge(0, 1, 10);
    addEdge(0, 2, 15);
    addEdge(0, 3, 30);
    addEdge(1, 3, 40);
    addEdge(2, 3, 50);

    primAlgorithm(adjList, V);  // Call the Prim's algorithm function

    return 0;
}
