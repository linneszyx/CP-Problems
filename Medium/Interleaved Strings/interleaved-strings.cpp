//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
      bool solve(string A, string B, string C,int inda,int indb,int indc,vector<vector<int>>&dp){
        if(inda==A.size() and indb==B.size() and indc==C.size()){
            return 1;
        }
        if(indc==C.size() and (indb<B.size() || inda<C.size()) ){
            return 0;
        }
        if(dp[inda][indb]!=-1){
            return dp[inda][indb];
        }
        int lenax=0,lenab=0;
        if(A[inda]==C[indc]){
            lenax=solve(A,B,C,inda+1,indb,indc+1,dp);
        }
        if(B[indb]==C[indc]){
           lenab= solve(A,B,C,inda,indb+1,indc+1,dp);
        }
        
        return dp[inda][indb]=(lenax | lenab);
    }
    
    bool isInterleave(string A, string B, string C) 
    {
        vector<vector<int>>dp(A.size()+1,vector<int>(B.size()+1,-1));
        return solve(A,B,C,0,0,0,dp);
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends