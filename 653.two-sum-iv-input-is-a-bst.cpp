/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
 *
 * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (61.01%)
 * Likes:    5600
 * Dislikes: 237
 * Total Accepted:    439.1K
 * Total Submissions: 719.4K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * Given the root of a binary search tree and an integer k, return true if
 * there exist two elements in the BST such that their sum is equal to k, or
 * false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [5,3,6,2,4,null,7], k = 9
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [5,3,6,2,4,null,7], k = 28
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 10^4].
 * -10^4 <= Node.val <= 10^4
 * root is guaranteed to be a valid binary search tree.
 * -10^5 <= k <= 10^5
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
   /**
    * If the current node is null, return false. If the current node's value is in the set, return
    * true. Otherwise, add the current node's value to the set and recursively call the function on the
    * left and right subtrees
    * 
    * @param root the root of the tree
    * @param k the target sum
    * @param s the set of numbers we've seen so far
    * 
    * @return true if there is a pair of nodes in the tree whose sum is equal to k.
    */
    bool find(TreeNode* root, int k, unordered_set<int>& s) {
        if (!root) return false;
        if (s.count(k - root->val)) return true;
        s.insert(root->val);
        return find(root->left, k, s) || find(root->right, k, s);
    }
    /**
     * If the current node's value is in the set, then we've found the target. Otherwise, add the
     * current node's value to the set and recurse on the left and right children
     * 
     * @param root the root of the tree
     * @param k the target value
     * 
     * @return A boolean value.
     */
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return find(root, k, s);
    }
};
// @lc code=end

