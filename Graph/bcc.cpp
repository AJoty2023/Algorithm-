#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define MULTIPLE_TEST \
    int t;            \
    cin >> t;         \
    while (t--)
#define inf 1e9 + 7

// local array size = 1e5, global = 1e8
// int = 1e9, long long = 1e18
//  1 sec = 1e7 ~ 1e8

const int N = 1e7 + 10;

void graph_input(int &V, int &E, vector<int> *g)
{
    cin >> V >> E;

    for (int i = 0; i < 100; i++)
        g[i].clear();

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void popStackTillEdge(stack<pair<int, int>> &st, pair<int, int> &edge, vector<vector<pair<int, int>>> &ans)
{
    vector<pair<int, int>> comp;
    while (!st.empty())
    {
        comp.push_back({st.top().first, st.top().second});
        // cout<<st.top().first<<"-"<<st.top().second<<", ";

        if (st.top() == edge)
        {
            st.pop();
            break;
        }
        st.pop();
    }
    // cout<<'\n';
    ans.push_back(comp);
}

void bcc_util(int vertex, vector<int> *adj, vector<int> &low, vector<int> &disc, vector<int> &parent, unordered_set<int> &visited, int time, stack<pair<int, int>> &st, vector<vector<pair<int, int>>> &ans)
{
    visited.insert(vertex);

    disc[vertex] = low[vertex] = ++time;

    int children = 0;

    for (auto child : adj[vertex])
    {
        pair<int, int> edge = {vertex, child};

        if (visited.find(child) == visited.end())
        {
            children++;
            parent[child] = vertex;

            st.push(edge);

            bcc_util(child, adj, low, disc, parent, visited, time, st, ans);

            low[vertex] = min(low[vertex], low[child]);

            if (parent[vertex] == -1 && children > 1)
            {
                popStackTillEdge(st, edge, ans);
            }

            if (parent[vertex] != -1 && low[child] >= disc[vertex])
            {
                popStackTillEdge(st, edge, ans);
            }
        }

        else if (parent[vertex] != child && disc[child] < low[vertex])
        {
            low[vertex] = disc[child];
            st.push(edge);
        }
    }
}

vector<vector<pair<int, int>>> bcc(vector<int> *adj, int V)
{
    vector<int> disc(V, inf);
    vector<int> low(V, inf);
    vector<int> parent(V, -1);

    unordered_set<int> visited;
    int time = 0;

    vector<vector<pair<int, int>>> ans;

    for (int vertex = 0; vertex < V; vertex++)
    {
        if (visited.find(vertex) == visited.end())
        {
            stack<pair<int, int>> st;
            bcc_util(vertex, adj, low, disc, parent, visited, time, st, ans);

            vector<pair<int, int>> comp;
            while (!st.empty())
            {
                comp.push_back({st.top().first, st.top().second});
                st.pop();
            }
            ans.push_back(comp);
        }
    }

    return ans;
}

int main()
{

    fastio
        freopen("in.txt", "r", stdin);

    int V, E;
    vector<int> g[100];

    graph_input(V, E, g);

    auto ans = bcc(g, V);

    for (auto li : ans)
    {
        for (auto edge : li)
        {
            cout << edge.first << "-" << edge.second << ", ";
        }
        cout << '\n';
    }

    return 0;
}