//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
     int solve(vector<int> wt,int w,int n,vector<vector<int>> &dp)
    {
        if(n==0)
        {
            if(w==0)
           {
            return 1;
           }
           
            return 0;
        }
        if(dp[n][w]!=-1)
        {
            return dp[n][w];
        }
        if(wt[n-1]<=w)
        {
            return dp[n][w] = solve(wt,w-wt[n-1],n-1,dp)||solve(wt,w,n-1,dp);
        }
        else{
            return dp[n][w] =solve(wt,w,n-1,dp);
        }
    }
    bool isSubsetSum(vector<int>wt, int w){
        // code here 
        int n = wt.size();
        
        vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
        for(int j=0;j<=w;j++)
        {
            dp[0][j]=0;
        }
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=w;j++)
            {
                if(wt[i-1]<=j)
                {
                    dp[i][j] = dp[i-1][j-wt[i-1]]||dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][w];
        // return solve(arr,sum,n,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends