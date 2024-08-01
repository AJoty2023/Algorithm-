#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int src;
    int dest;   
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
        graph[dest].push_back({dest, src}); // For undirected graph
    }
}

bool isCyclicUtil(vector<Edge>* graph, bool vis[], int curr, int par) {
    vis[curr] = true;
    for (int i = 0; i < graph[curr].size(); i++) {
        Edge e = graph[curr][i];
        if (vis[e.dest] && e.dest != par) { // Case 1
            bool isCycle = isCyclicUtil(graph, vis, e.dest, curr);
            if (isCycle)
                return true;
        } else if (e.dest == par) { // Case 2
            continue;
        } else { // Case 3
            return true;
        }
    }
    return false;
}

bool isCyclic(vector<Edge>* graph, int V) {
    bool* vis = new bool[V];
    for (int i = 0; i < V; i++) {
        vis[i] = false;
    }
    for (int i = 0; i < V; i++) {
        if (!vis[i] && isCyclicUtil(graph, vis, i, -1)) {
            delete[] vis;
            return true;
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
