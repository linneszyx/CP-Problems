//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
int tsp(int i,int mask,vector<vector<int>> &cost,vector<vector<int>> &dp){
        int n=cost.size();
        if(mask==0) return cost[i][0];
        if(dp[i][mask] != -1) return dp[i][mask];
        int mini=1e9;
        for(int j=0;j<n;j++){
            if(mask & (1<<j)){
                mini=min(mini,(cost[i][j]+tsp(j,(mask^(1<<j)),cost,dp)));
            }
        }
        return dp[i][mask] =mini;
    }
public:
    int total_cost(vector<vector<int>> cost){
        int n=cost.size();
        if(n==1) return 0;
        int mask=(1<<n)-1 ;
        vector<vector<int>> dp(n+1,vector<int> (mask+1,-1));
        mask=mask^(1<<0);
        return tsp(0,mask,cost,dp);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends