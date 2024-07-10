//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // code here
        int c=0;
        for(int i=0;i<n;i+=1) {
            for(int j=0;j<m;j+=1){
                if(mat[i][j]==1 and i-1>=0 and j-1>=0) {
                    mat[i][j] = min({mat[i-1][j],mat[i][j-1],mat[i-1][j-1]})+1;
                }
                c=max(mat[i][j],c);
            }
        }
        return c;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends