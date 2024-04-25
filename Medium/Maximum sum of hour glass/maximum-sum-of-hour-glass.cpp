//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
int sumHourGlass(int x, int y, vector<vector<int>>& mat) {
        int sum = 0;
        // Top row of hourglass
        sum += mat[x][y] + mat[x][y+1] + mat[x][y+2];
        // Middle of hourglass
        sum += mat[x+1][y+1];
        // Bottom row of hourglass
        sum += mat[x+2][y] + mat[x+2][y+1] + mat[x+2][y+2];
        return sum;
    }
    
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        if (n < 3 || m < 3) return -1;
        int ans = INT_MIN;
        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                ans = max(ans, sumHourGlass(i, j, mat));
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        cout << ob.findMaxSum(N, M, Mat) << "\n";
    }
}
// } Driver Code Ends