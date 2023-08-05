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
    private:
        vector<TreeNode*> solve(int s,int e){
            if(s>e) return {nullptr};
            vector<TreeNode*> at;
            for(int i=s;i<=e;i++){
                vector<TreeNode*> lt = solve(s,i-1);
                vector<TreeNode*> rt = solve(i+1,e);
                for(TreeNode *l : lt){
                    for(TreeNode *r : rt){
                        TreeNode * ct = new TreeNode(i);
                        ct->left = l;
                        ct->right = r;
                        at.push_back(ct);
                    }
                }
            }
            return at;
        }
public:

    vector<TreeNode*> generateTrees(int n) {
        return n ? solve(1,n) : vector<TreeNode*>();    
    }
};