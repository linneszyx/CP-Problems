class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if(obstacleGrid.empty() or obstacleGrid[0].empty() or obstacleGrid[0][0]==1) return 0;
           int m = obstacleGrid.size();
           int n = obstacleGrid[0].size();
           vector<int> p(n,0);
           vector<int> c(n,0);
           p[0] =1 ;
           for(int i=0;i<m;i++){
               c[0]=obstacleGrid[i][0]==1?0:p[0];
               for(int j=1;j<n;j++){
                   c[j]=obstacleGrid[i][j]==1?0:c[j-1]+p[j];
               }
               p=c;
           }
           return p[n-1];
    }
};