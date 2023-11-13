//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int solve(int i1,int i2,string &X,string &Y,vector<vector<int>>&dp){
        if(i1<0 or i2<0) return 0;
        if(dp[i1][i2]!=-1) return dp[i1][i2];
        if(X[i1]==Y[i2]) return dp[i1][i2] = 1+solve(i1-1,i2-1,X,Y,dp);
        return dp[i1][i2]=max(solve(i1-1,i2,X,Y,dp),solve(i1,i2-1,X,Y,dp));
    }
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int c = solve(m-1,n-1,X,Y,dp);
        return X.size()+Y.size()-c;
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends