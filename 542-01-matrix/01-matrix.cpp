class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0) q.push({i,j});
                else mat[i][j] = -1;
            }
        }
        vector<int> dp = {-1,0,1,0,-1};
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                pair<int,int> p = q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int r = p.first + dp[j];
                    int c = p.second + dp[j+1];
                    if(r>=0 and c>=0 and r<m and c<n and mat[r][c]==-1){
                        mat[r][c] = 1 + mat[p.first][p.second];
                        q.push({r,c});
                    }
                }
            }
        }
        return mat; 
    }
};