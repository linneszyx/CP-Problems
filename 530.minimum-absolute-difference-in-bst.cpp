/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
 *
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (56.81%)
 * Likes:    2708
 * Dislikes: 142
 * Total Accepted:    195.8K
 * Total Submissions: 342.7K
 * Testcase Example:  '[4,2,6,1,3]'
 *
 * Given the root of a Binary Search Tree (BST), return the minimum absolute
 * difference between the values of any two different nodes in the tree.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [4,2,6,1,3]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,0,48,null,null,12,49]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [2, 10^4].
 * 0 <= Node.val <= 10^5
 * 
 * 
 * 
 * Note: This question is the same as 783:
 * https://leetcode.com/problems/minimum-distance-between-bst-nodes/
 * 
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
    void traverse(TreeNode* root, vector<int>& v) {
        if (root == nullptr) return;
        v.push_back(root->val);
        traverse(root->left, v);
        traverse(root->right, v);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> v;
        traverse(root, v);
        sort(v.begin(), v.end());
        int min = INT_MAX;
        for (int i = 1; i < v.size(); i++) {
            if (v[i] - v[i - 1] < min) {
                min = v[i] - v[i - 1];
            }
        }
        return abs(min);
    }
};
// @lc code=end

