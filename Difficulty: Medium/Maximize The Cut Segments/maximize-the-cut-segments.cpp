//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
  int solve(int n, int x, int y, int z, vector<int>&dp){
        
        if(n<0) return INT_MIN;
        if(n==0) return 0;
        
        if(dp[n]!=-1) return dp[n];
        
        
        int cl1=solve(n-x, x, y, z, dp);
        int cl2=solve(n-y, x, y, z, dp);
        int cl3=solve(n-z, x, y, z, dp);
        
        return dp[n]=1+max(cl1, max(cl2, cl3));
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int>dp(n+1, -1);
        return max(0, solve(n, x, y, z, dp));
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends