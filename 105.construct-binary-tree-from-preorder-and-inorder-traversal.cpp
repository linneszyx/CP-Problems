/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        TreeNode *root = new TreeNode();
        if (preorder.size() == 0)
            return nullptr;
        root->val = preorder[0];
        int i = 0;
        for (; i < inorder.size(); i++)
        {
            if (inorder[i] == preorder[0])
                break;
        }
        vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + i + 1);
        vector<int> left_inorder(inorder.begin(), inorder.begin() + i);
        vector<int> right_preorder(preorder.begin() + i + 1, preorder.end());
        vector<int> right_inorder(inorder.begin() + i + 1, inorder.end());
        root->left = buildTree(left_preorder, left_inorder);
        root->right = buildTree(right_preorder, right_inorder);
        return root;
    }
};
// @lc code=end
