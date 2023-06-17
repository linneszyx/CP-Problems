/*
 * @lc app=leetcode id=1187 lang=cpp
 *
 * [1187] Make Array Strictly Increasing
 */

// @lc code=start
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        int n = arr1.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = INT_MIN;
        for (int i = 0; i < n; ++i) {
            vector<int> tmp(n + 1, INT_MAX);
            for (int j = 0; j <= i + 1; ++j) {
                if (arr1[i] > dp[j]) {
                    tmp[j] = arr1[i];
                }
                if (j > 0) {
                    auto it = upper_bound(arr2.begin(), arr2.end(), dp[j - 1]);
                    if (it != arr2.end()) {
                        tmp[j] = min(tmp[j], *it);
                    }
                }
            }
            dp = tmp;
        }
        for (int i = 0; i <= n; ++i) {
            if (dp[i] != INT_MAX) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

