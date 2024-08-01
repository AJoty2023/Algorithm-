#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u); // for an undirected graph
}

void BFS(vector<vector<int>>& adjList, int start) {
    int V = adjList.size();
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS starting from vertex " << start << ": ";
    while (!q.empty()) {
        int currVertex = q.front();
        q.pop();
        cout << currVertex << " ";

        for (int adjVertex : adjList[currVertex]) {
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                q.push(adjVertex);
            }
        }
    }
    cout << endl;
}

void DFS(vector<vector<int>>& adjList, int start) {
    int V = adjList.size();
    vector<bool> visited(V, false);

    function<void(int)> dfs = [&](int currVertex) {
        cout << currVertex << " ";
        for (int adjVertex : adjList[currVertex]) {
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                dfs(adjVertex);
            }
        }
    };

    cout << "DFS starting from vertex " << start << ": ";
    visited[start] = true;
    dfs(start);
    cout << endl;
}

int main() {
    int V = 5;
    vector<vector<int>> adjList(V);

    // Adding edges to the graph
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 4);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 3, 4);

    // Printing the adjacency list
    cout << "Adjacency List:\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " : ";
        for (int adjVertex : adjList[i]) {
            cout << adjVertex << " ";
        }
        cout << endl;
    }

    // Perform BFS and DFS starting from vertex 2
    BFS(adjList, 2);
    DFS(adjList, 2);

    return 0;
}
