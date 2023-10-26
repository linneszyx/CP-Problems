//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

#define vvi vector<vector<int>>
class Solution{
  public:
  int f(string &s1,string &s2,int i,int j,vvi &dp){
      if(i<=0 or j<=0) return 0;
      if(dp[i][j]!=-1) return dp[i][j];
      if(s1[i-1]==s2[j-1]) return 1+f(s1,s2,i-1,j-1,dp);
      int x = f(s1,s2,i-1,j,dp);
      int y = f(s1,s2,i,j-1,dp);
      return dp[i][j] = max(x,y);
  }
    int minimumNumberOfDeletions(string s) { 
        // code here
        int n = s.length();
        vvi dp(n+1,vector<int>(n+1,-1));
        string s2 = s;
        reverse(s2.begin(),s2.end());
        int lps = f(s,s2,n,n,dp);
        return n - lps;
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends