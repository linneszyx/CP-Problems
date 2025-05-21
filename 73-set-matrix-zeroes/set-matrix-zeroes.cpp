class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_set<int> sr,sc;
        for(int i=0;i<n;i+=1){
            for(int j=0;j<m;j+=1){
                if(matrix[i][j]==0) {
                    sr.insert(i);
                    sc.insert(j);
                }
            }
        }
        for(int i=0;i<n;i+=1) {
            for(int j=0;j<m;j+=1){
                if(sr.count(i)>0 || sc.count(j)>0) matrix[i][j]=0;
            }
        }
    }
};