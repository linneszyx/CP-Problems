class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n-1;i+=1) {
            for(int j=0;j<m-1;j+=1) {
                if(mat[i][j]!=mat[i+1][j+1]) 
                {
                    return false;
                }
            }
        }
        return true;
    }
};