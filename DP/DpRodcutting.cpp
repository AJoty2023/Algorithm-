//Given a rod of length N inches and an array of prices, prices[] that contains prices of all peices of size smaller than N. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

//Unbounded knapsack

#include<bits/stdc++.h>
using namespace std;

int rodCutting(int price[], int n) {
    int dp[n + 1];
    dp[0] = 0; // Initialize the value for the rod of length 0 as 0

    // Calculate the maximum value for each rod length from 1 to n
    for (int len = 1; len <= n; len++) {
        int maxVal = INT_MIN;
        for (int cut = 0; cut < len; cut++) {
            maxVal = max(maxVal, price[cut] + dp[len - cut - 1]);
        }
        dp[len] = maxVal;
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter the length of the rod: ";
    cin >> n;

    int price[n];
    cout << "Enter the prices for each length: ";
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }

    int result = rodCutting(price, n);
    cout << "Maximum obtainable value: " << result << endl;

    return 0;
}
