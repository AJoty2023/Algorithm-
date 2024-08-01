#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

struct RodCutter {
    vector<int> prices;
    unordered_map<int, int> memo; // Memoization table for top-down

    RodCutter(const vector<int>& p) : prices(p) {}

    // Brute Force
    int rodCuttingBruteForce(int n) {
        if (n <= 0) {
            return 0;
        }

        int max_value = INT_MIN;

        for (int i = 1; i <= n; ++i) {
            max_value = max(max_value, prices[i - 1] + rodCuttingBruteForce(n - i));
        }

        return max_value;
    }

    // Memoization (Top-Down)
    int rodCuttingMemoization(int n) {
        if (n <= 0) {
            return 0;
        }

        if (memo.find(n) != memo.end()) {
            return memo[n];
        }

        int max_value = INT_MIN;

        for (int i = 1; i <= n; ++i) {
            max_value = max(max_value, prices[i - 1] + rodCuttingMemoization(n - i));
        }

        memo[n] = max_value;

        return max_value;
    }

    // Memoization (Bottom-Up)
    int rodCuttingBottomUp(int n) {
        vector<int> dp(n + 1, INT_MIN);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] = max(dp[i], prices[j - 1] + dp[i - j]);
            }
        }

        return dp[n];
    }

    int findMaxValue(int rod_length, int method) {
        if (method == 1) {
            return rodCuttingBruteForce(rod_length);
        } else if (method == 2) {
            memo.clear();
            return rodCuttingMemoization(rod_length);
        } else if (method == 3) {
            return rodCuttingBottomUp(rod_length);
        } else {
            return -1; // Invalid method
        }
    }
};

int main() {
    // Adjust the prices for a simple problem instance
    vector<int> prices = {2, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int rod_length = 10;

    RodCutter rodCutter(prices);

    for (int method = 1; method <= 3; ++method) {
        auto start = high_resolution_clock::now();
        int max_value = rodCutter.findMaxValue(rod_length, method);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        cout << "Method " << method << ":" << endl;
        cout << "Maximum value: " << max_value << endl;
        cout << "Execution time: " << duration.count() << " microseconds" << endl << endl;
    }

    return 0;
}
