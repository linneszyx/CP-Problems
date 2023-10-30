//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int solve(string a, string b, int i, int j , vector<vector<int>> &dp)
     {
         if(i==a.length())
         {
             return (b.length()-j);
         }
         if(j==b.length())
         {
             return (a.length()-i);
         }
         if(dp[i][j]!=-1)
         return dp[i][j];
         int ans =0;
          if(a[i]==b[j]) 
         return solve(a,b,i+1,j+1,dp);
         else
         {
             int ins=1+ solve(a,b,i,j+1,dp);
             int rem=1+ solve(a,b,i+1,j,dp);
             int re=1+ solve(a,b,i+1,j+1,dp);
             ans = min(ins, min(rem,re));
             return dp[i][j]= ans;
         }
         
         
     }
     int editDistance(string s, string t) {
         int i=0; int j=0;
         vector<vector<int>>dp(s.length(), vector<int> (t.length(),-1)) ;
          int r =solve(s,t,i,j,dp);
          return r;
          
       
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends