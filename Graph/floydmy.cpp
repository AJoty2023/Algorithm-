#include <iostream>
#include <vector>
#include <limits>

using namespace std;

#define INF 999

void floydWarshall(vector<vector<int>> &dist, int V)
{
    // Floyd-Warshall algorithm
    for (int k = 0; k < V; ++k)
    {
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                if (i == j)
                {
                    dist[i][j] = 0;
                }
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main()
{
    int V, E;

    cout << "Enter the number of vertices: ";
    cin >> V;

    // Initialize the adjacency matrix
    vector<vector<int>> dist(V, vector<int>(V, INF));

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges and their weights (u v weight):" << endl;
    for (int i = 0; i < E; ++i)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        dist[u][v] = weight;
    }

    // Floyd-Warshall algorithm
    floydWarshall(dist, V);

    // Print the result
    cout << "Shortest paths between vertices:" << endl;
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            if (dist[i][j] == INF)
                cout << "INF";

            else
                cout << dist[i][j];
            if (j != V - 1)
                cout << "\t";
        }
        cout << endl;
    }

    return 0;
}
