/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
 *
 * https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/
 *
 * algorithms
 * Easy (56.91%)
 * Likes:    2679
 * Dislikes: 377
 * Total Accepted:    182.1K
 * Total Submissions: 312K
 * Testcase Example:  '[4,2,6,1,3]'
 *
 * Given the root of a Binary Search Tree (BST), return the minimum difference
 * between the values of any two different nodes in the tree.
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
 * The number of nodes in the tree is in the range [2, 100].
 * 0 <= Node.val <= 10^5
 * 
 * 
 * 
 * Note: This question is the same as 530:
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/
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
       if(root!=nullptr){
            v.push_back(root->val);
            traverse(root->left,v);
            traverse(root->right,v);
       }
         else{
              return;
         }
    }
    int minDiffInBST(TreeNode* root) {
       vector<int>v;
         traverse(root,v);
         sort(v.begin(),v.end());
         int res = INT_MAX;
         for(int i=1;i<v.size();i++){
             res = min(res,v[i]-v[i-1]);
         }
            return res;
    }
};
// @lc code=end

