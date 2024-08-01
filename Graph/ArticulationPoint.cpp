#include <bits/stdc++.h>
using namespace std;

void APUtil(vector<vector<int>> &adj, int u, vector<bool> &visited,
            vector<int> &disc, vector<int> &low, int &time, int parent,
            vector<bool> &isAP)
{
    int children = 0;

    visited[u] = true;

    disc[u] = low[u] = ++time;

    for (auto v : adj[u])
    {

        if (!visited[v])
        {
            children++;
            APUtil(adj, v, visited, disc, low, time, u, isAP);

            low[u] = min(low[u], low[v]);

            if (parent != -1 && low[v] >= disc[u])
                isAP[u] = true;
        }

        else if (v != parent)
            low[u] = min(low[u], disc[v]);
    }

    if (parent == -1 && children > 1)
        isAP[u] = true;
}

void AP(vector<vector<int>> &adj, int V)
{   
    
    vector<bool> visited(V, false);
    vector<int> disc(V, -1);
    vector<int> low(V, -1);
    //int disc[V] = {0};
    //int low[V];
    //bool visited[V] = {false};
    vector<bool> isAP(V, false);
    int time = 0, par = -1;

    for (int u = 0; u < V; u++)
        if (!visited[u])
            APUtil(adj, u, visited, disc, low, time, par, isAP);

    for (int u = 0; u < V; u++)
        if (isAP[u] == true)
            cout << u << " ";
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    AP(adj, n);
    cout << endl;

    return 0;
}
