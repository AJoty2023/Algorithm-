#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int src;
    int dest;
    int wt;
    Edge(int s, int d, int w) : src(s), dest(d), wt(w) {}
};

void createGraph(vector<Edge> graph[], int V, int E) {
    for (int i = 0; i < E; i++) {
        int src, dest, wt;
        cout << "Enter source, destination, and weight for edge " << i + 1 << ": ";
        cin >> src >> dest >> wt;

        graph[src].push_back(Edge(src, dest, wt));
    }
}

void bellmanFord(vector<Edge> graph[], int src, int V) {
    int dist[V];
    for (int i = 0; i < V; i++) {
        if (i != src)
            dist[i] = INT_MAX;
        else
            dist[i] = 0;
    }

    // Relax edges |V| - 1 times
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < V; j++) {
            for (const Edge& e : graph[j]) {
                int u = e.src;
                int v = e.dest;
                int wt = e.wt;
                if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
    }

    // Detecting Negative Weight Cycle
    for (int j = 0; j < V; j++) {
        for (const Edge& e : graph[j]) {
            int u = e.src;
            int v = e.dest;
            int wt = e.wt;
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                cout << "Negative weight cycle exists" << endl;
                return;
            }
        }
    }

    // Print distances
    for (int i = 0; i < V; i++) {
        cout << "Shortest distance from " << src << " to " << i << ": " << dist[i] << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<Edge> graph[V];
    createGraph(graph, V, E);

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    bellmanFord(graph, src, V);

    return 0;
}
