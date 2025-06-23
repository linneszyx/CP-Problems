class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        if(nums.size()==1) return new TreeNode(nums[0]);
        int m = nums.size()/2;
        TreeNode* root = new TreeNode(nums[m]);
        vector<int> l(nums.begin(),nums.begin()+m);
        vector<int> r(nums.begin()+m+1,nums.end());
        root->left = sortedArrayToBST(l);
        root->right = sortedArrayToBST(r);
        return root;
    }
};