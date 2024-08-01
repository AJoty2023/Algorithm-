#include <iostream>
#include <vector>
#include <string>

using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();

    // Create a DP table to store the length of LCS
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP table using a bottom-up approach
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; // Characters match; increment LCS length.
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Characters don't match; take the maximum.
            }
        }
    }

    return dp[m][n]; // Length of the LCS.
}

int main() {
    string text1, text2;

    cout << "Enter the first string: ";
    cin >> text1;

    cout << "Enter the second string: ";
    cin >> text2;

    int result = longestCommonSubsequence(text1, text2);
    cout << "Length of Longest Common Subsequence: " << result << endl;

    return 0;
}
