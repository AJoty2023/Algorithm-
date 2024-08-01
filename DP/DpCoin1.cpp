#include<bits/stdc++.h>
using namespace std;
const int N = 2510;

int dp[N];

int calculation(int amount, vector<int>& coins){
    if(amount == 0) return 0;
    if(dp[amount] != -1) return dp[amount];

    int ans = INT_MAX;
    for(int coin : coins){
        if(amount - coin >= 0){
            ans = min(ans + 0LL , calculation(amount - coin, coins) + 1LL);
        }
    }
    return dp[amount] = ans;
}

int coinChange(vector<int>& coins, int amount){
    memset(dp, -1, sizeof(dp));
    int ans = calculation(amount, coins);

    return ans == INT_MAX ? -1 : ans;
}

int main(){
    // Read coin denominations from the user
    int n;
    cout << "Enter the number of coin denominations: ";
    cin >> n;
    vector<int> coins(n);
    cout << "Enter the coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // Read the target amount from the user
    int amount;
    cout << "Enter the target amount: ";
    cin >> amount;

    int result = coinChange(coins, amount);
    cout << "Minimum number of coins needed: " << result << endl;

    return 0;
}
