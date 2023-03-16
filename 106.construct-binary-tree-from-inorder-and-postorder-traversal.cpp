/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        TreeNode *root = nullptr;
        int n = inorder.size();
        if (n == 0)
            return root;
        root = new TreeNode(postorder[n - 1]);
        stack<TreeNode *> st;
        st.push(root);
        int i = n - 2, j = n - 1;
        while (i >= 0)
        {
            TreeNode *node = st.top();
            if (node->val != inorder[j])
            {
                node->right = new TreeNode(postorder[i]);
                st.push(node->right);
                i--;
            }
            else
            {
                while (!st.empty() && st.top()->val == inorder[j])
                {
                    node = st.top();
                    st.pop();
                    j--;
                }
                node->left = new TreeNode(postorder[i]);
                st.push(node->left);
                i--;
            }
        }
        return root;
    }
};
// @lc code=end
