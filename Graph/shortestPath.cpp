#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adjList(N);
    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        adjList[U].push_back(V);
    }

    vector<int> distance(N, INF);
    distance[0] = 0; // Distance from source node 0 to itself is 0

    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : adjList[current]) {
            if (distance[neighbor] == INF) {
                distance[neighbor] = distance[current] + 1;
                q.push(neighbor);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << i << ": ";
        if (distance[i] != INF) {
            cout << distance[i];
        } else {
            cout << "Not Reachable";
        }
        cout << endl;
    }

    return 0;
}

