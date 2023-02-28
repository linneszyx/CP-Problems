/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
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
   /**
    * The function returns a string that is the preorder traversal of the tree, and the string is the
    * key of the hashmap. 
    * 
    * The hashmap stores the number of times the string appears in the tree. 
    * 
    * If the string appears more than once, then the root of the subtree is added to the result vector.
    * 
    * @param root the root of the tree
    * @param subTree a hashmap that stores the subtree string and the number of times it appears in the
    * tree.
    * @param res the vector of TreeNode pointers that will be returned
    * 
    * @return The string representation of the tree.
    */
    string helper(TreeNode *root, unordered_map<string, int> &subTree, vector<TreeNode *> &res)
    {
        if (!root)
            return "#";
        string s = to_string(root->val) + "," + helper(root->left, subTree, res) + "," + helper(root->right, subTree, res);
        if (subTree[s] == 1)
            res.push_back(root);
        subTree[s]++;
        return s;
    }
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
     unordered_map<string,int> subTree;
        vector<TreeNode*> res;
        helper(root,subTree,res);
        return res;
    }
};
// @lc code=end
