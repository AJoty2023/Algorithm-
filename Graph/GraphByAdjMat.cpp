#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>

int main(){
    int n,m;
    cin >> n >> m;

    vvi graph(n+1, vi(n+1,0));

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;

        //undirected
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    cout << "Adjacency matrix of above graph is given by: " << endl;

    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            cout << graph[i][j] <<" ";
           
        }
         cout << endl;
    }

    if(graph[3][7] == 1){
        cout << "There is a edge" << endl;
    }
    else{
        cout<< "No egde" <<endl;
    }

    return 0;
}