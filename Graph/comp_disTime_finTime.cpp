#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList;
vector<bool> visited;
vector<int> discovery_time;
vector<int> finishing_time;
vector<int> component; // To store the component number for each node
int time_counter = 0;
int current_component = 0;

// Recursive DFS function to find components with discovery time and finishing time
void dfs(int node) {
    visited[node] = true;
    component[node] = current_component;
    time_counter++;
    discovery_time[node] = time_counter;

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }

    time_counter++;
    finishing_time[node] = time_counter;
}

int main() {
    int N, M;
    cin >> N >> M;

    adjList.resize(N);
    visited.resize(N, false);
    discovery_time.resize(N, 0);
    finishing_time.resize(N, 0);
    component.resize(N, -1);

    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        adjList[U].push_back(V);
        adjList[V].push_back(U); // Undirected graph, so add edges in both directions
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            current_component++;
            dfs(i);
        }
    }

    for (int i = 0; i < N; i++) {
        cout << i << ": " << component[i] << " " << discovery_time[i] << " " << finishing_time[i] << endl;
    }

    return 0;
}

