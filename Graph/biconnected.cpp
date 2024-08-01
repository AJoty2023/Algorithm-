#include <bits/stdc++.h>
using namespace std;

void DFS(int u, int parent, int& time, vector<vector<int>>& adjList,
         vector<int>& disc, vector<int>& low, stack<pair<int, int>>& st) {
    disc[u] = low[u] = ++time;

    for (int v : adjList[u]) {
        if (v == parent)
            continue;

        if (disc[v] == -1) {
            st.push({u, v});
            DFS(v, u, time, adjList, disc, low, st);
            low[u] = min(low[u], low[v]);

            if (low[v] >= disc[u]) {
                cout << "Biconnected component: ";
                while (st.top() != make_pair(u, v)) {
                    cout << st.top().first << " -- " << st.top().second << " ";
                    st.pop();
                }
                cout << st.top().first << " -- " << st.top().second << endl;
                st.pop();
            }
        } else if (disc[v] < disc[u]) {
            st.push({u, v});
            low[u] = min(low[u], disc[v]);
        }
    }
}

void findBiconnectedComponents(vector<vector<int>>& adjList) {
    int V = adjList.size();
    vector<int> disc(V, -1), low(V, -1);
    stack<pair<int, int>> st;
    int time = 0;

    for (int i = 0; i < V; ++i) {
        if (disc[i] == -1)
            DFS(i, -1, time, adjList, disc, low, st);
        while (!st.empty()) {
            cout << "Biconnected component: " << st.top().first << " -- " << st.top().second << endl;
            st.pop();
        }
    }
}

int main() {
    int V = 7;
    vector<vector<int>> adjList(V);

    // Adding edges to the adjacency list
    adjList[0].push_back(1);
    adjList[1].push_back(0);
    adjList[1].push_back(2);
    adjList[2].push_back(1);
    adjList[0].push_back(2);
    adjList[2].push_back(0);
    adjList[1].push_back(3);
    adjList[3].push_back(1);
    adjList[1].push_back(4);
    adjList[4].push_back(1);
    adjList[1].push_back(6);
    adjList[6].push_back(1);
    adjList[3].push_back(5);
    adjList[5].push_back(3);
    adjList[4].push_back(5);
    adjList[5].push_back(4);

    cout << "Biconnected Components:\n";
    findBiconnectedComponents(adjList);

    return 0;
}
