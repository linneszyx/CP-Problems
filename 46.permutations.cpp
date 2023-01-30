/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (75.16%)
 * Likes:    14355
 * Dislikes: 242
 * Total Accepted:    1.5M
 * Total Submissions: 2M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an array nums of distinct integers, return all the possible
 * permutations. You can return the answer in any order.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * Example 2:
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 * Example 3:
 * Input: nums = [1]
 * Output: [[1]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * All the integers of nums are unique.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>>result;
    void backper(vector<int> &nums,int s){
        int n = nums.size();
        if(s==n) result.push_back(nums);
        for(int i=s;i<n;i++){
            swap(nums[i],nums[s]);
            backper(nums,s+1);
            swap(nums[i],nums[s]);
        } 
    }
    vector<vector<int>> permute(vector<int>& nums) {
        backper(nums,0);
        return result;
    }
};
// @lc code=end

