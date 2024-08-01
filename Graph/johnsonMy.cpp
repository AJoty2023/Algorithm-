#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int minDistance(vector<int> &dist, vector<bool> &visited)
{
    int minDist = INF;
    int minVertex = -1;

    for (int v = 0; v < dist.size(); v++)
    {
        if (!visited[v] && dist[v] <= minDist)
        {
            minDist = dist[v];
            minVertex = v;
        }
    }

    return minVertex;
}

void Dijkstra(vector<vector<int>> &graph, vector<vector<int>> &modifiedGraph, int src)
{
    int numVertices = graph.size();
    vector<bool> sptSet(numVertices, false);
    vector<int> dist(numVertices, INF);

    dist[src] = 0;

    for (int count = 0; count < numVertices; count++)
    {
        int curVertex = minDistance(dist, sptSet);
        sptSet[curVertex] = true;

        for (int v = 0; v < numVertices; v++)
        {
            if (!sptSet[v] && dist[curVertex] != INF &&
                (dist[curVertex] + modifiedGraph[curVertex][v]) < dist[v] &&
                graph[curVertex][v] != 0)
            {
                dist[v] = dist[curVertex] + modifiedGraph[curVertex][v];
            }
        }
    }

    cout << "Shortest distances from vertex " << src << ":\n";
    for (int vertex = 0; vertex < numVertices; vertex++)
    {
        cout << "Vertex " << vertex << ": ";
        if (dist[vertex] == INF)
        {
            cout << "INF" << endl;
        }
        else
        {
            cout << dist[vertex] << endl;
        }
    }
}

vector<int> BellmanFord(vector<vector<int>> &edges, vector<vector<int>> &graph)
{
    int numVertices = graph.size();
    vector<int> dist(numVertices + 1, INF);
    dist[numVertices] = 0;

    for (int i = 0; i < numVertices; i++)
    {
        edges.push_back({numVertices, i, 0});
    }

    for (int i = 0; i < numVertices; i++)
    {
        for (const vector<int> &edge : edges)
        {
            int src = edge[0];
            int des = edge[1];
            int weight = edge[2];

            if (dist[src] != INF && dist[src] + weight < dist[des])
            {
                dist[des] = dist[src] + weight;
            }
        }
    }

    // Exclude the last element, which was added for computation
    return vector<int>(dist.begin(), dist.begin() + numVertices);
}

void JohnsonAlgorithm(vector<vector<int>> &graph)
{
    int numVertices = graph.size();
    vector<vector<int>> edges;

    // Create a list of edges for Bellman-Ford Algorithm
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            if (graph[i][j] != 0)
            {
                edges.push_back({i, j, graph[i][j]});
            }
        }
    }

    vector<int> modifyWeights = BellmanFord(edges, graph);

    vector<vector<int>> modifiedGraph(numVertices, vector<int>(numVertices, 0));

    // Modify the weights to get rid of negative weights
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            if (graph[i][j] != 0)
            {
                modifiedGraph[i][j] = graph[i][j] + modifyWeights[i] - modifyWeights[j];
            }
        }
    }

    cout << "Modified Graph:\n";
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            cout << modifiedGraph[i][j] << " ";
        }
        cout << endl;
    }

    for (int src = 0; src < numVertices; src++)
    {
        cout << "\nShortest Distances with vertex " << src << " as the source:\n";
        Dijkstra(graph, modifiedGraph, src);
    }
}

int main()
{
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    vector<vector<int>> graph(numVertices, vector<int>(numVertices));

    int numEdges;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the edges and weights (src des weight):\n";
    for (int i = 0; i < numEdges; i++)
    {
        int src, des, weight;
        cin >> src >> des >> weight;
        graph[src][des] = weight;
    }

    JohnsonAlgorithm(graph);

    return 0;
}
