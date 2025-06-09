class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<int> v;
        if(mat.empty()) return v;
        int rowStart=0,rowEnd=rows-1,startCol=0,endCol=cols-1;
        while(rowStart<=rowEnd and startCol<=endCol){
         for(int i=startCol;i<=endCol;i+=1)  v.push_back(mat[rowStart][i]);
         for(int i=rowStart+1;i<=rowEnd;i+=1)  v.push_back(mat[i][endCol]);
         for(int i=endCol-1;i>=startCol;i--) { if(rowStart==rowEnd) break; v.push_back(mat[rowEnd][i]);}
         for(int i=rowEnd-1;i>=rowStart+1;i--) {
            if(startCol==endCol) break; v.push_back(mat[i][startCol]);}
         rowStart++;
         startCol++;
         rowEnd--;
         endCol--;
        }
        return v;
    }
};