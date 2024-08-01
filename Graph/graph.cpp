#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> g[100]; // Assuming nodes are numbered from 0 to 99

    for (int i = 0; i < N; i++)
        g[i].clear();

    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        g[U].push_back(V);
    }

    for (int i = 0; i < N; i++) {
        cout << i << ": ";
        for (int j = 0; j < g[i].size(); j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
