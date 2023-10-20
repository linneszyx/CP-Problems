//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
   int eggDrop(int egg, int floorVal) {
    vector<vector<int>> dp(egg+1,vector<int>(floorVal+1,0));
    
    for(int e=0;e<=egg;e++){
        dp[e][1] = 1;
    }
    for(int f=0;f<=floorVal;f++){
        dp[1][f] = f;
    }

    for(int f=1;f<=floorVal;f++){
        for(int e=2;e<=egg;e++){
            int ans = 1e9,attempts;
    
            for(int flr = 1;flr<=f;flr++){
                attempts = 1 + max(dp[e-1][flr-1],dp[e][f-flr]);
                ans = min(ans,attempts);
            }
            
            dp[e][f] = ans;
        }
    }
    return dp[egg][floorVal];
}
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends