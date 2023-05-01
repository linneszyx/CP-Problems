/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int,vector<int>,greater<int>> mh;
       for(int n:nums) {
        mh.push(n);
        if(mh.size()>k) mh.pop();
       }
       return mh.top();
    }
};
// @lc code=end

