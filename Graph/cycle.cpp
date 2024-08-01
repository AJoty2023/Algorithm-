#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adjList;
vector<bool> visited;

// Helper function to perform DFS and check for cycles
bool hasCycle(int node, int parent) {
    visited[node] = true;

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            if (hasCycle(neighbor, node))
                return true;
        } else if (neighbor != parent) {
            return true;
        }
    }

    return false;
}

int main() {
    int N, M;
    cin >> N >> M;

    adjList.resize(N);
    visited.resize(N, false);

    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        adjList[U].push_back(V);
        adjList[V].push_back(U); // Undirected graph, so add edges in both directions
    }

    bool hasAnyCycle = false;
    for (int i = 0; i < N; i++) {
        if (!visited[i] && hasCycle(i, -1)) {
            hasAnyCycle = true;
            break;
        }
    }

    cout << (hasAnyCycle ? "Yes" : "No") << endl;

    return 0;
}

