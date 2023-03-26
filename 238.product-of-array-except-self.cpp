/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return {0};
        }
        int i,temp = 1;
        vector<int> prod(n,1);
        for(i=0;i<n;i++){
            prod[i] = temp;
            temp *= nums[i];
        }
        temp = 1;
        for(i=n-1;i>=0;i--){
            prod[i] *= temp;
            temp *= nums[i];
        }
        return prod;
    }
};
// @lc code=end

