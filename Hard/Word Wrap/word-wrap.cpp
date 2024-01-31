//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
   int solve(vector<int>& nums, int i , int j , int k , vector<int> &dp){
        if(i>j) return 0;
        if(dp[i]!=-1)return dp[i];
        int ans = INT_MAX;
        int sum =0;
        for(int idx=i ; idx<=j ; idx++){
            sum+=nums[idx];
            if(sum<=k && idx==j)return dp[i]=0;
            if(sum<=k){
                int extra = (k-sum)*(k-sum);
                int cost = extra + solve(nums,idx+1,j,k,dp);
                ans = min(ans,cost);
                sum++;
            }
        }
        
        return dp[i]=ans;
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(nums,0,n-1,k,dp);
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends