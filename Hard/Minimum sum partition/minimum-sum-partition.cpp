//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
int solve(int id,int s1,int fin,int arr[],int n,vector<vector<int>> &dp)
    {
        if(id==n) return abs((fin-s1)-s1);
        if(dp[id][s1]!=-1) return dp[id][s1];
        return dp[id][s1] = min(solve(id+1,s1+arr[id],fin,arr,n,dp),solve(id+1,s1,fin,arr,n,dp));
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int su = 0;
	    for(int i=0;i<n;i++) su+=arr[i];
	    vector<vector<int>> dp(n+1,vector<int>(su+1,-1));
	    return solve(0,0,su,arr,n,dp);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends