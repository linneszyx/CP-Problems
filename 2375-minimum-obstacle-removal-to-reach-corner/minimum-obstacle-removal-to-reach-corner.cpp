class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        deque<pair<int,int>> dq;
        dist[0][0]=0;
        dq.push_front({0,0});
        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        while(!dq.empty()) {
            auto [x,y]=dq.front();
            dq.pop_front();
            for(auto [dx,dy] : dir) {
                int nx=x+dx;
                int ny=y+dy;
                if(nx>=0 and nx<m and ny>=0 and ny<n){
                    int ndist = dist[x][y]+grid[nx][ny];
                    if(ndist<dist[nx][ny]) {
                        dist[nx][ny]=ndist;
                        if(grid[nx][ny]==0) dq.push_front({nx,ny});
                        else dq.push_back({nx,ny});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};