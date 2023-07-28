/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */

// @lc code=start
class Solution {
public:
   vector<vector<int>> dp;
   int score(vector<int> &nums,int l,int r){
       if(l==r){
           return nums[l];
       }
       if(dp[l][r]!=-1){
           return dp[l][r];
       }
       int a = nums[l] - score(nums,l+1,r);
       int b = nums[r] - score(nums,l,r-1);
       return dp[l][r] = max(a,b);
       }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,vector<int>(n,-1));
        return score(nums,0,n-1)>=0;
    }
};
// @lc code=end

