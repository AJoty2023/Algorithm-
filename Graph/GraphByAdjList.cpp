#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
const int N = 1e5+2, MOD = 1e9+7;

int main(){
    int n,m;
    cin >> n >> m;

    vi list[N];

     for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;

        //undirected
        list[x].push_back(y);
        list[y].push_back(x);
    }

    cout << "Adjacency list of above graph is given by: " << endl;

    for(int i=1; i<n+1; i++){
        cout << i <<" -> ";
        vector<int> :: iterator it;
        for(it = list[i].begin(); it!=list[i].end(); it++){
            cout << *it <<" ";
        }
         cout << endl;
    }


    return 0;
}