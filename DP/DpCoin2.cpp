//Return the number of combinations that make up that amount.

#include<bits/stdc++.h>
using namespace std;
const int N = 2510;

int dp[310][10010];

int calculation(int index, int amount, vector<int>& coins){
    if(amount == 0) return 1;

    if(index < 0) return 0;
    if(dp[index][amount] != -1) return dp[index][amount];

    int ways = 0;
    for(int coin_amount = 0; coin_amount <= amount; coin_amount +=coins[index]){
        ways += calculation(index-1, amount - coin_amount, coins);
    }
        
    return dp[index][amount] = ways;
}

int coinChange(vector<int>& coins, int amount){
    memset(dp, -1, sizeof(dp));
    int ans = calculation(coins.size()-1, amount, coins);

    return ans;
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
    cout << "Total number of ways: " << result << endl;

    return 0;
}