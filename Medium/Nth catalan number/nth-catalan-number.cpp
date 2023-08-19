//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

const int mod = 1e9+7;
class Solution
{
    public:
    
    //Function to find the nth catalan number.
     int precompute(int n, int dp[]){
        dp[0]=1;
        for(int i=1; i<=n; i++){
            dp[i]=0;
            for(int j=0; j<i; j++){
                dp[i] = (dp[i] + (1LL * dp[j] * dp[i - j - 1]) % mod) % mod;
            }
        }
        return dp[n];
    }
    int findCatalan(int n) 
    {
       int dp[n+1];
        memset(dp, 0, sizeof(dp));
        return precompute(n, dp);
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends