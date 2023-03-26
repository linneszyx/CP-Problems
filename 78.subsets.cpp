/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution
{
public:
    void dfs(vector<int> &nums, int x, vector<int> &path, vector<vector<int>> &res)
    {
        if (x == nums.size())
        {
            res.push_back(path);
            return;
        }
        dfs(nums, x + 1, path, res);
        path.push_back(nums[x]);
        dfs(nums, x + 1, path, res);
        path.pop_back();
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> path;
        dfs(nums, 0, path, res);
        return res;
    }
};
// @lc code=end
