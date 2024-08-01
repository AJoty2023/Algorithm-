#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;
    vector<bool> visited;
    stack<int> topologicalSort;
    bool hasCycle = false;

public:
    Graph(int V) {
        adjList.resize(V);
        visited.resize(V, false);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        // For a directed graph, we don't add the reverse edge (u -> v) to avoid affecting cycle detection.
    }

    void dfs(int node) {
        visited[node] = true;

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor])
                dfs(neighbor);
        }
        topologicalSort.push(node);
    }

    void runDFS() {
        int V = adjList.size();
        for (int i = 0; i < V; i++) {
            if (!visited[i])    dfs(i);
        }
    }

    void printSort() {
        while (!topologicalSort.empty()) {
            cout << topologicalSort.top() << " ";
            topologicalSort.pop();
        }
    }
};

int main() {
    int n = 6, m;
    // cin >> n >> m;

    Graph g(n);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 1);
    g.addEdge(5, 2);
    // for (int i = 0; i < m; i++) {
    //     int u, v;
    //     cin >> u >> v;
    //     g.addEdge(u, v);
    // }

    g.runDFS();
    g.printSort();

    return 0;
}
