#include <iostream>
#include <vector>
#include <stack>
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
    }
}

void topoSortUtil(vector<Edge>* graph, int curr, bool vis[], stack<int>& s) {
    vis[curr] = true;
    for (int i = 0; i < graph[curr].size(); i++) {
        Edge e = graph[curr][i];
        if (!vis[e.dest]) {
            topoSortUtil(graph, e.dest, vis, s);
        }
    }
    s.push(curr);
}

void topoSort(vector<Edge>* graph, int V) {
    bool* vis = new bool[V];
    for (int i = 0; i < V; i++) {
        vis[i] = false;
    }
    stack<int> s;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            topoSortUtil(graph, i, vis, s);
        }
    }
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    delete[] vis;
}

int main() {
    int V, E; // Number of vertices and edges
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;
    
    vector<Edge>* graph = new vector<Edge>[V];
    createGraph(graph, V, E);
    
    topoSort(graph, V);
    
    delete[] graph;
    return 0;
}
