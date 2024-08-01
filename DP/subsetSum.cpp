#include <iostream>
#include <vector>

using namespace std;

bool subsetSum(vector<int>& nums, int targetSum) {
    int n = nums.size();

    // Create a DP table with dimensions (n+1) x (targetSum+1)
    vector<vector<bool>> dp(n + 1, vector<bool>(targetSum + 1, false));

    // Initialize the base case: an empty subset can always achieve a sum of 0
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // Fill the DP table using a bottom-up approach
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= targetSum; j++) {
            if (j < nums[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }

    return dp[n][targetSum];
}

int main() {
    int n, targetSum;

    cout << "Enter the number of elements in the set: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the target sum: ";
    cin >> targetSum;

    if (subsetSum(nums, targetSum)) {
        cout << "Subset with sum " << targetSum << " exists." << endl;
    } else {
        cout << "No subset with sum " << targetSum << " exists." << endl;
    }

    return 0;
}
