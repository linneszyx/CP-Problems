
class Solution {
public:
    int maxi = INT_MIN;
    int ff(TreeNode* root) {
        if (!root)
            return 0;
        int l = max(ff(root->left), 0);
        int r = max(ff(root->right), 0);
        int np = root->val + l + r;
        maxi = max(maxi, np);
        return root->val + max(l, r);
    }
    int maxPathSum(TreeNode* root) {
        ff(root);
        return maxi;
    }
};