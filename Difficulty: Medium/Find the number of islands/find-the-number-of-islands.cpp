//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
  int dx[8] = {-1,-1,0,1,1,1,0,-1};
    int dy[8] = {0,1,1,1,0,-1,-1,-1};
    
    void makeAllZero(vector<vector<char>>& grid, int i, int j, int &n, int &m){
        if(i>=n || j>=m)
            return;
            
        grid[i][j] = '0';
        for(int k=0; k<8; k++){
            int newX = i + dx[k];
            int newY = j + dy[k];
            
            if(newX >=0 && newY>=0 && newX<n && newY<m && grid[newX][newY] == '1'){
                makeAllZero(grid,newX,newY,n,m);
            }
            
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    makeAllZero(grid, i, j, n, m);
                }
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends