//Frog jumping , 1 take start kore n no stone e poushate hobe, frog ith stone take i+1 stone a jate pare or i+2 stone e jaite pare, minimum path cost ber korte hobe. 

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int h[N];
int dp[N];

int minCost(int i){

    if(i==0) return 0;

    if(dp[i] != -1) return dp[i];

    int cost = INT_MAX;

    
    //way 1 one stone level jump
    cost = min(cost, minCost(i-1)+abs(h[i]-h[i-1]));

    //way 2 two stone level jump
    if(i>1){
        cost = min(cost, minCost(i-2)+abs(h[i]-h[i-2]));
    }
    return dp[i] = cost;
}

int main(){
    memset(dp,-1,sizeof(dp));                                                        

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> h[i];
    }
    cout << minCost(n-1);
}