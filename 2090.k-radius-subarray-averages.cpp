/*
 * @lc app=leetcode id=2090 lang=cpp
 *
 * [2090] K Radius Subarray Averages
 */

// @lc code=start
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n,-1);
        long long int sum = 0;
        for (int i=0;i<2*k+1;i++) {
            if(i>=n) return res;
            sum += nums[i];
        }
        int s1 = sum/(2*k+1);
        res[k] = s1;
        for (int i=k+1;i<n-k;i++) {
            sum += nums[i+k];
            sum -= nums[i-k-1];
            int s2 = sum/(2*k+1);
            res[i] = s2;
        }
        return res;
    }
};
// @lc code=end

