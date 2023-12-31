//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    private:
    int solve(int index,int sum,int n,int arr[])
    {
        if(index==n)
        {
            if((sum%20==0 || sum%24==0 || sum==2024) && sum!=0)
            {
                return 1;
            }
            return 0;
        }
        
        int notTake=solve(index+1,sum,n,arr);
        int take=solve(index+1,sum+arr[index],n,arr);
        
        return (notTake || take);
    }
    int mem(int index,int sum,int n,int arr[],vector<vector<int>> &dp)
    {
        if(index==n)
        {
            if((sum%20==0 || sum%24==0 || sum==2024) && sum!=0)
            {
                return 1;
            }
            return 0;
        }
        if(dp[index][sum]!=-1)
        {
            return dp[index][sum];
        }
        int notTake=mem(index+1,sum,n,arr,dp);
        int take=mem(index+1,sum+arr[index],n,arr,dp);
        
        dp[index][sum]= (notTake || take);
        return dp[index][sum];
    }
    
  
    public:
    int isPossible(int N , int coins[]) 
    {
        vector<vector<int>> dp(N+1,vector<int>(2024,-1));
        // return solve(0,0,N,coins);
        return mem(0,0,N,coins,dp);
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends