/*
 * @lc app=leetcode id=1601 lang=cpp
 *
 * [1601] Maximum Number of Achievable Transfer Requests
 */

// @lc code=start
class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int row = requests.size();
        int ans = 0;
        for (int i = 0; i < (1 << row); ++i) {
            vector<int> cnt(n);
            int cur = 0;
            for (int j = 0; j < row; ++j) {
                if (i & (1 << j)) {
                    cnt[requests[j][0]]--;
                    cnt[requests[j][1]]++;
                    cur++;
                }
            }
            bool flag = true;
            for (int j = 0; j < n; ++j) {
                if (cnt[j] != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};
// @lc code=end

