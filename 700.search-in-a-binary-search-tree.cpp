/*
 * @lc app=leetcode id=700 lang=cpp
 *
 * [700] Search in a Binary Search Tree
 *
 * https://leetcode.com/problems/search-in-a-binary-search-tree/description/
 *
 * algorithms
 * Easy (77.33%)
 * Likes:    4576
 * Dislikes: 163
 * Total Accepted:    608.7K
 * Total Submissions: 785.5K
 * Testcase Example:  '[4,2,7,1,3]\n2'
 *
 * You are given the root of a binary search tree (BST) and an integer val.
 * 
 * Find the node in the BST that the node's value equals val and return the
 * subtree rooted with that node. If such a node does not exist, return
 * null.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [4,2,7,1,3], val = 2
 * Output: [2,1,3]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [4,2,7,1,3], val = 5
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 5000].
 * 1 <= Node.val <= 10^7
 * root is a binary search tree.
 * 1 <= val <= 10^7
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root->val ==val){
            return root;
        }
        TreeNode *node = root;
        while (node!=NULL){
            if(node->val == val){
                return node;
            }
            if(node->val > val){
                node = node->left;
            }else{
                node = node->right;
            }
        }
        return NULL;
        
    }
};
// @lc code=end

