/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (31.84%)
 * Likes:    13891
 * Dislikes: 1143
 * Total Accepted:    1.8M
 * Total Submissions: 5.8M
 * Testcase Example:  '[2,1,3]'
 *
 * Given the root of a binary tree, determine if it is a valid binary search
 * tree (BST).
 * 
 * A valid BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [2,1,3]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is
 * 4.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 10^4].
 * -2^31 <= Node.val <= 2^31 - 1
 * 
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
    bool flag;
    long long pre = -1e18;
   /**
    * It checks if the tree is a binary search tree.
    * 
    * @param root the root of the tree
    * 
    * @return a boolean value.
    */
    void dfs(TreeNode* root) {
        if (!root) return;
       /* Checking if the left subtree is a binary search tree. */
        dfs(root->left);
        if (root->val <= pre) {
            flag = false;
            return;
        }
        pre = root->val;
        /* Checking if the right subtree is a binary search tree. */
        dfs(root->right);
    }
    bool isValidBST(TreeNode* root) {
        flag = true;
        dfs(root);
        return flag;
    }
};
// @lc code=end

