#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int src;
    int dest;
    int wt;
    Edge(int s, int d, int w) : src(s), dest(d), wt(w) {}
};

void createGraph(vector<Edge>* graph, int E) {
    for (int i = 0; i < E; i++) {
        int src, dest, wt;
        cout << "Enter source, destination, and weight for edge " << i + 1 << ": ";
        cin >> src >> dest >> wt;

        graph[src].push_back(Edge(src, dest, wt));
        graph[dest].push_back(Edge(dest, src, wt)); // Add for undirected graph
    }
}

struct Pair {
    int v;
    int wt;
    Pair(int v, int wt) : v(v), wt(wt) {}
    bool operator>(const Pair& p2) const {
        return this->wt > p2.wt;
    }
};

void primAlgo(vector<Edge>* graph, int V) {
    bool* vis = new bool[V]{false};
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    pq.push(Pair(0, 0));
    int cost = 0;

    while (!pq.empty()) {
        Pair curr = pq.top();
        pq.pop();

        if (!vis[curr.v]) {
            vis[curr.v] = true;
            cost += curr.wt;

            for (const Edge& e : graph[curr.v]) {
                if (!vis[e.dest]) {
                    pq.push(Pair(e.dest, e.wt));
                }
            }
        }
    }

    cout << "Minimum Spanning Tree Cost: " << cost << endl;
    delete[] vis;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<Edge>* graph = new vector<Edge>[V];
    createGraph(graph, E);
    primAlgo(graph, V);

    delete[] graph;
    return 0;
}
