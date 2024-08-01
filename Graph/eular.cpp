#include <bits/stdc++.h> // Includes the necessary header files.
using namespace std;

void addEdge(vector<list<int>>& adj, int v, int w) {
    adj[v].push_back(w); // Adds an edge from vertex v to vertex w.
    adj[w].push_back(v); // Adds an edge from vertex w to vertex v (since it's an undirected graph).
}

void dfs(vector<list<int>>& adj, int v, bool visited[]) {
    visited[v] = true; // Mark the current vertex as visited.

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i]) dfs(adj, *i, visited); // Recursive depth-first search for unvisited neighbors.
}

bool isConnected(vector<list<int>>& adj, int V) {
    bool visited[V];
    int i;
    for (i = 0; i < V; i++) visited[i] = false; // Initialize visited array.

    for (i = 0; i < V; i++)
        if (adj[i].size() != 0) break; // Find the first non-empty vertex.

    if (i == V) return true; // If all vertices are empty, the graph is trivially connected.

    dfs(adj, i, visited); // Perform DFS from the first non-empty vertex.

    for (i = 0; i < V; i++)
        if (visited[i] == false && adj[i].size() > 0) return false; // If any unvisited vertex has edges, graph is not connected.

    return true; // If DFS reaches all non-empty vertices, the graph is connected.
}

int findOddDegreeVertex(vector<list<int>>& adj, int V) {
    for (int i = 0; i < V; i++)
        if (adj[i].size() & 1) return i; // Find the first vertex with an odd degree.
    return -1; // If no odd-degree vertices are found, return -1.
}

int isEulerian(vector<list<int>>& adj, int V, int& startVertex) {
    if (isConnected(adj, V) == false) return 0; // If the graph is not connected, it can't be Eulerian.

    int odd = 0;
    for (int i = 0; i < V; i++)
        if (adj[i].size() & 1) odd++; // Count the number of vertices with odd degree.

    if (odd > 2) return 0; // If more than two vertices have odd degree, it can't be Eulerian.
    
    startVertex = (odd == 0) ? 0 : findOddDegreeVertex(adj, V); // Determine the starting vertex for the Eulerian path/cycle.

    return (odd) ? 1 : 2; // Return 1 for Euler path, 2 for Euler cycle, 0 for neither.
}

void printEulerPath(vector<list<int>>& adj, int V, int startVertex) {
    stack<int> circuit; // Stack to store the Eulerian circuit/path.
    int curr = startVertex;

    while (!circuit.empty() || adj[curr].size() > 0) {
        if (adj[curr].size() == 0) {
            cout << curr << " "; // Print the vertex when there are no more edges.
            curr = circuit.top(); // Backtrack to the previous vertex.
            circuit.pop(); // Remove the vertex from the stack.
        } else {
            circuit.push(curr); // Push the current vertex onto the stack.
            int nextVertex = adj[curr].front(); // Get the next connected vertex.
            adj[curr].pop_front(); // Remove the edge between current and next vertex.
            for (int v : adj[nextVertex]) {
                if (v == curr) {
                    adj[nextVertex].remove(v); // Remove the corresponding edge from the other vertex.
                    break;
                }
            }
            curr = nextVertex; // Move to the next vertex.
        }
    }
    cout << curr << endl; // Print the last vertex.
}

int main() {
    int V = 5; // Number of vertices
    vector<list<int>> adj1(V); // Adjacency list representation for the graph
    addEdge(adj1, 1, 0); // Add edges to the graph
    addEdge(adj1, 0, 2);
    addEdge(adj1, 2, 1);
    addEdge(adj1, 0, 3);
    addEdge(adj1, 3, 4);

    int startVertex;
    int res = isEulerian(adj1, V, startVertex); // Determine if the graph has an Euler path or cycle
    if (res == 0)
        cout << "Graph is not Eulerian\n";
    else if (res == 1) {
        cout << "Graph has an Euler path:\n";
        printEulerPath(adj1, V, startVertex); // Print the Euler path
    } else {
        cout << "Graph has an Euler cycle:\n";
        printEulerPath(adj1, V, startVertex); // Print the Euler cycle
    }

    // Similarly, define and test other graphs...

    return 0;
}
