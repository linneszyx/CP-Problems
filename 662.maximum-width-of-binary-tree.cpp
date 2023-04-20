/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        int max_width = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            int left = q.front().second;
            int right = q.back().second;
            max_width = max(max_width, right-left+1);
            for(int i=0; i<size; i++){
                auto node_index = q.front();
                TreeNode* node = node_index.first;
                int index = node_index.second-right;
                q.pop();
                if(node->left!=nullptr) q.push({node->left, 2*index+1});
                if(node->right!=nullptr) q.push({node->right, 2*index+2});
            }
        }
        return max_width;
    }
};
// @lc code=end

