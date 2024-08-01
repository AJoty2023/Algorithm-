//frog ith stone take i+1, i+2, i+3 and so on i+k prjonto jump korte pare, etar jnne minimum path cost koto hobe?

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int k;
int h[N];
int dp[N];

int minCost(int i){

    if(i==0) return 0;

    if(dp[i] != -1) return dp[i];

    int cost = INT_MAX;

    for(int j = 1; j <= k; ++j){ //ekane j=1 mane bujai i-1, basically i-j
        if(i-j >= 0){
            cost = min(cost, minCost(i-j) + abs(h[i]-h[i-j]));
        }
    }

    return dp[i] = cost;
}

int main(){
    memset(dp,-1,sizeof(dp));

    int n;
    cin >> n >> k;

    for(int i=0; i<n; i++){
        cin >> h[i];
    }
    cout << minCost(n-1);
}