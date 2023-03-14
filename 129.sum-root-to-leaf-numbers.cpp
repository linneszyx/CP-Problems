/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    void dfs(TreeNode *root,vector<int> &path,int &sum){
        path.push_back(root->val);
        if(root->left==nullptr&&root->right==nullptr){
            int temp=0;
            for(int i=0;i<path.size();i++){
                temp=temp*10+path[i];
            }
            sum+=temp;
        }
        if(root->left!=nullptr){
            dfs(root->left,path,sum);
        }
        if(root->right!=nullptr){
            dfs(root->right,path,sum);
        }
        path.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        if (root == nullptr) {
            return sum;
        }
        vector<int> path;
        dfs(root, path, sum);
        return sum;
    }
};
// @lc code=end

