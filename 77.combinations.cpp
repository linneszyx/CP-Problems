/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (66.49%)
 * Likes:    5627
 * Dislikes: 178
 * Total Accepted:    634.7K
 * Total Submissions: 952.6K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * chosen from the range [1, n].
 * 
 * You may return the answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4, k = 2
 * Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
 * Explanation: There are 4 choose 2 = 6 total combinations.
 * Note that combinations are unordered, i.e., [1,2] and [2,1] are considered
 * to be the same combination.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1, k = 1
 * Output: [[1]]
 * Explanation: There is 1 choose 1 = 1 total combination.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 20
 * 1 <= k <= n
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void back_track(int i,int n,int k,vector<int> &ans,vector<vector<int>> &res){
        if(ans.size()==k){
            res.push_back(ans);
            return;
        }
        for(int j=i;j<=n;j++){
            ans.push_back(j);
            back_track(j+1,n,k,ans,res);
            ans.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
     vector<vector<int>> res;
       vector<int> ans;
       back_track(1,n,k,ans,res);
       return res; 
    }
};
// @lc code=end

