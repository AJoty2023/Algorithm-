#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int src;
    int dest;
   // Edge(int s, int d) : src(s), dest(d) {}
};

void createGraph(vector<Edge>* graph, int V, int E) {
    for (int i = 0; i < V; i++) {
        graph[i] = vector<Edge>();
    }
    
    cout << "Enter source and destination for each edge:" << endl;
    for (int i = 0; i < E; i++) {
        int src, dest;
        cin >> src >> dest;
        graph[src].push_back({src, dest});
    }
}

bool isCyclicUtil(vector<Edge>* graph, int curr, bool vis[], bool stack[]) {
    vis[curr] = true;
    stack[curr] = true;
    for (int i = 0; i < graph[curr].size(); i++) {
        Edge e = graph[curr][i];
        if (stack[e.dest]) {
            return true;
        } else if (!vis[e.dest] && isCyclicUtil(graph, e.dest, vis, stack)) {
            return true;
        }
    }
    stack[curr] = false;
    return false;
}

bool isCyclic(vector<Edge>* graph, int V) {
    bool* vis = new bool[V];
    for (int i = 0; i < V; i++) {
        vis[i] = false;
    }
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            bool cycle = isCyclicUtil(graph, i, vis, new bool[V]);
            if (cycle) {
                delete[] vis;
                return true;
            }
        }
    }
    delete[] vis;
    return false;
}

int main() {
    int V, E; // Number of vertices and edges
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;
    
    vector<Edge>* graph = new vector<Edge>[V];
    createGraph(graph, V, E);
    
    cout << (isCyclic(graph, V) ? "true" : "false") << endl;
    
    delete[] graph;
    return 0;
}
