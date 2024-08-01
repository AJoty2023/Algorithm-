#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;  // Maximum number of nodes in the graph

int parent[N], sz[N];  // Arrays for parent pointers and sizes of sets

// Function to initialize a new set with a single node
void make(int v){
    parent[v] = v;  // Setting itself as the parent
    sz[v] = 1;      // Initial size of the set is 1
}

// Function to find the representative of the set using path compression
int find(int v){
    if(parent[v] == v){
        return parent[v];  // If v is its own parent, return v
    }
    return parent[v] = find(parent[v]);  // Otherwise, update parent and return
}

// Function to merge two sets using union by size
void Union(int a, int b){
    a = find(a);  // Find the representative of set containing a
    b = find(b);  // Find the representative of set containing b

    if(a != b){  // If they are not in the same set
        if(sz[a] < sz[b]){
            swap(a, b);  // Swap a and b so that b's set is larger (different from minimum spanning tree)
        }
        parent[b] = a;        // Set b's parent as a
        sz[a] += sz[b];        // Update the size of a's set
    }
}

int main(){
    int n, m;
    cin >> n >> m;  // Read the number of nodes and edges

    vector<pair<int, pair<int, int>>> edges;  // Vector to store edges

    // Read edges and their weights and store them in the edges vector
    for(int i = 0; i < m; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({-wt, {u, v}});  // Reverse the sign of weights to find maximum spanning tree
    }

    sort(edges.begin(), edges.end());  // Sort edges by weight in descending order

    // Initialize each node as a separate set
    for(int i = 1; i <= n; i++){
        make(i);
    }

    int total_cost = 0;  // Initialize the total cost of the maximum spanning tree

    // Iterate through each edge in sorted order
    for(auto &edge : edges){
        int wt = -edge.first;        // Reverse the sign to get the original weight
        int u = edge.second.first;   // First node of the edge
        int v = edge.second.second;  // Second node of the edge

        // If the nodes u and v are already in the same set, skip this edge
        if(find(u) == find(v)){
            continue;
        }

        Union(u, v);  // Merge the sets containing nodes u and v

        total_cost += wt;  // Add the weight of the edge to the total cost
        cout << u << "----" << v << endl;  // Print the selected edge
    }

    cout << total_cost << endl;  // Print the total cost of the maximum spanning tree

    return 0;  // Return 0 to indicate successful completion
}
