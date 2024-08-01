#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int src;
    int dest;
};

void createGraph(vector<vector<Edge>>& graph, int V, int E) {
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

void printAllPaths(vector<vector<Edge>>& graph, int src, int tar, string path, vector<bool>& vis) {
    if (src == tar) {
        cout << path << endl;
        return;
    }
    for (int i = 0; i < graph[src].size(); i++) {
        Edge e = graph[src][i];
        if (!vis[e.dest]) {
            vis[e.dest] = true;
            printAllPaths(graph, e.dest, tar, path + "->" + to_string(e.dest), vis);
            vis[e.dest] = false;
        }
    }
}

int main() {
    int V, E; // Number of vertices and edges
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;
    
    vector<vector<Edge>> graph(V);
    createGraph(graph, V, E);
    
    int src, tar;
    cout << "Enter source and target nodes: ";
    cin >> src >> tar;
    
    vector<bool> vis(V, false);
    vis[src] = true;
    printAllPaths(graph, src, tar, to_string(src), vis);
    
    return 0;
}
