#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int INF = INT_MAX;

int dp[N][N]; // Dynamic programming table

// Function to find the minimum difficulty to reach the bottom-right cell
int minDifficulty(vector<vector<int>>& grid, int m, int n) {
    dp[0][0] = grid[0][0]; // Initialize the top-left cell with its own difficulty

    // Initialize the first row of dp table
    for (int j = 1; j < n; j++) {
        dp[0][j] = max(dp[0][j - 1], grid[0][j]);
    }

    // Initialize the first column of dp table
    for (int i = 1; i < m; i++) {
        dp[i][0] = max(dp[i - 1][0], grid[i][0]);
    }

    // Fill the DP table
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            // Calculate the minimum difficulty to reach (i, j) by taking the minimum
            // of the maximum difficulty from the cell above and the cell to the left,
            // and then adding the difficulty of the current cell.
            dp[i][j] = min(max(dp[i - 1][j], dp[i][j - 1]), grid[i][j]);
        }
    }

    return dp[m - 1][n - 1]; // Return the minimum difficulty to reach the bottom-right cell
}

int main() {
    int m, n;

    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    cout << "Enter the difficulty levels for each cell:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j]; // Read the difficulty levels for each cell from the user
        }
    }

    int result = minDifficulty(grid, m, n); // Calculate the minimum difficulty

    cout << "Minimum difficulty to reach the bottom-right cell: " << result << endl;

    return 0;
}
