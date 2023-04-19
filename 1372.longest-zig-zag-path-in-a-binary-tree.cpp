/*
 * @lc app=leetcode id=1372 lang=cpp
 *
 * [1372] Longest ZigZag Path in a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int& res, int left, int right) {
        if (!root) return;
        res = max(res, max(left, right));
        dfs(root->left, res, 0, left + 1);
        dfs(root->right, res, right + 1, 0);
    }
    int longestZigZag(TreeNode* root) {
        int res = 0;
        dfs(root, res, 0, 0);
        return res;
    }
};
// @lc code=end

