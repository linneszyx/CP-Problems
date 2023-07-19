//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        //code here
        int n = A.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<n; i++){
            dp[i][i] = 1;
        }
        for(int i=0; i<n-1; i++){
            if(A[i] == A[i+1]){
                dp[i][i+1] = 2;
            }
            else{
                dp[i][i+1] = 1;
            }
        }
        for(int i=2; i<n; i++){
            for(int j=0; j<n-i; j++){
                if(A[j] == A[j+i]){
                    dp[j][j+i] = 2 + dp[j+1][j+i-1];
                }
                else{
                    dp[j][j+i] = max(dp[j][j+i-1], dp[j+1][j+i]);
                }
            }
        }
        return dp[0][n-1];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends