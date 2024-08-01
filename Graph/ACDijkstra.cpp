#include <iostream>
#include <vector>
#include <queue>
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

vector<int> dijkstra(vector<Edge> graph[], int V, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const Edge& e : graph[u]) {
            int v = e.dest;
            int weight = e.wt;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
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

    vector<int> dist = dijkstra(graph, V, src);

    for (int i = 0; i < V; i++) {
        cout << "Shortest distance from " << src << " to " << i << ": " << dist[i] << endl;
    }

    return 0;
}
