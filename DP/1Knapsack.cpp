//There are N items, numbered 1,2,....N. For each i(1<= i <= N), Item i has a weught of wi and a value of vi. Find the maximum possible sum of the values of items that one takes home. 

#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int wt[105], val[105];
int dp[105][100005];

int knapsack(int ind, int wt_left){
    if(wt_left == 0) return 0;
    if(ind < 0) return 0;

    if(dp[ind][wt_left] != -1) return dp[ind][wt_left];

    //Dont choose item at ind
    int ans = knapsack(ind - 1, wt_left);

    //choose item ind
    if(wt_left - wt[ind] >= 0){
        ans = max(ans, knapsack(ind - 1, wt_left - wt[ind]) + val[ind]);
    }

    return dp[ind][wt_left] = ans;
}

int main(){
    memset(dp, -1, sizeof(dp));
    int n,w;
    cin >> n >> w;
    for(int i=0; i<n; i++){
        cin >> wt[i] >> val[i];
    }

    cout << knapsack(n-1,w);
}