//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int f(int ind,int total,vector<int>&cost,vector<vector<int>> &dp,int n){
        if(ind==n || total==0) return 0;
        if(dp[ind][total]!=-1) return dp[ind][total];
        int notTake = 0+f(ind+1,total,cost,dp,n);
        int take = 0;
        if(cost[ind]<=total) {
            take=1+f(ind+1,total-cost[ind]+floor(0.9*cost[ind]),cost,dp,n);
        }
        return dp[ind][total]=max(take,notTake);;
    }
    int max_courses(int n, int total, vector<int> &cost)
    {
        //Code Here
        vector<vector<int>> dp(n+1,vector<int>(total+1,-1));
        return f(0,total,cost,dp,n);
        
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends