#include <bits/stdc++.h>
using namespace std;

void bridgeUtil(int u, vector<bool> &visited, vector<int> &disc,
                vector<int> &low, vector<vector<int>> &adj, int parent)
{
    static int time = 0;

    // Mark the current node as visited
    visited[u] = true;

    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;

    // Go through all vertices adjacent to this
    for (int v : adj[u])
    {
        // 1. If v is parent
        if (v == parent)
            continue;

        // 2. If v is visited
        if (visited[v])
        {
            low[u] = min(low[u], disc[v]);
        }

        // 3. If v is not visited
        else
        {
            parent = u;
            bridgeUtil(v, visited, disc, low, adj, parent);

            // update the low of u as it's quite possible
            // a connection exists from v's descendants to u
            low[u] = min(low[u], low[v]);

            // if the lowest possible time to reach vertex v
            // is greater than discovery time of u it means
            // that v can be only be reached by vertex above v
            // so if that edge is removed v can't be reached so it's a bridge
            if (low[v] > disc[u])
                cout << u << "----" << v << endl;
        }
    }
}

void findBridges(int V, vector<vector<int>> &adj)
{
    // Mark all the vertices as not visited disc and low as -1
    vector<bool> visited(V, false);
    vector<int> disc(V, -1);
    vector<int> low(V, -1);

    // Initially there is no parent so let it be -1
    int parent = -1;

    for (int i = 0; i < V; i++)
        if (!visited[i])
            bridgeUtil(i, visited, disc, low, adj, parent);
}

int main()
{
    int n, m;
    cin >> n >> m;

    int cnt = 0;
    vector<vector<int>> adj_list(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    findBridges(n, adj_list);
}