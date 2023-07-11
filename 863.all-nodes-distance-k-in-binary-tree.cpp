/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        q.push(target);
        visited.insert(target);
        while (!q.empty() && k >= 0) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (k == 0) {
                    ans.push_back(node->val);
                }
                if (node->left && visited.find(node->left) == visited.end()) {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if (node->right && visited.find(node->right) == visited.end()) {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if (parent[node] && visited.find(parent[node]) == visited.end()) {
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }
            --k;
        }
        return ans;
    }
};
// @lc code=end

