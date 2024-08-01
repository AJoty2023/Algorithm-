#include <bits/stdc++.h>
using namespace std;

int lis(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    vector<int> tail;
    tail.push_back(nums[0]);

    for (int i = 1; i < n; i++) {
        if (nums[i] < tail[0]) {
            // If nums[i] is smaller than the smallest tail element, update the first element
            tail[0] = nums[i];
        } else if (nums[i] > tail.back()) {
            // If nums[i] is larger than the largest tail element, append it
            tail.push_back(nums[i]);
        } else {
            // If nums[i] falls in between, find the position to replace using binary search
            int pos = lower_bound(tail.begin(), tail.end(), nums[i]) - tail.begin();
            tail[pos] = nums[i];
        }
    }

    return tail.size(); // Return the length of the longest increasing subsequence
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = lis(nums);
    cout << result << endl;
    return 0;
}
