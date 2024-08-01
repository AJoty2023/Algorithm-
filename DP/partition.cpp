#include <iostream>
#include <vector>

using namespace std;

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int num : nums) {
        sum += num;
    }

    // If the sum is odd, it cannot be divided into two equal subsets
    if (sum % 2 != 0) {
        return false;
    }

    int targetSum = sum / 2;
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
    int n;

    cout << "Enter the number of elements in the set: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    if (canPartition(nums)) {
        cout << "The set can be partitioned into two subsets with equal sums." << endl;
    } else {
        cout << "The set cannot be partitioned into two subsets with equal sums." << endl;
    }

    return 0;
}
