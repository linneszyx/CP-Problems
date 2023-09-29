//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   void recursion(vector<vector<int> > &grid, int row, int col, int n, int m){
        
        grid[row][col] = 2;
        
        if (row > 0 and grid[row - 1][col] == 1)
            recursion(grid, row - 1, col, n, m);
        if (col > 0 and grid[row][col - 1] == 1)
            recursion(grid, row, col - 1, n, m);
        if (row + 1 < n and grid[row + 1][col] == 1)
            recursion(grid, row + 1, col, n, m);
        if (col + 1 < m and grid[row][col + 1] == 1)
            recursion(grid, row, col + 1, n, m);
    }
    
    int numberOfEnclaves(vector<vector<int>> &grid) {
        
        int n = (int)grid.size(), m = (int)grid[0].size();
        
        for (int i = 0; i < m; ++i) {
            if (grid[0][i] == 1)
                recursion(grid, 0, i, n, m);
            if (grid[n - 1][i] == 1)
                recursion(grid, n - 1, i, n, m);
        }
        
        for (int i = 0; i < n; ++i) {
            if (grid[i][0] == 1)
                recursion(grid, i, 0, n, m);
            if (grid[i][m - 1] == 1)
                recursion(grid, i, m - 1, n, m);
        }
        
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == 1)
                    ans++;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends