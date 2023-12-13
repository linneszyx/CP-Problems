//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll dp[100100], m=1000000007;
	Solution() {
	    memset(dp,-1,sizeof(dp));
	}
	ll countStrings(int n) {
	    if(n<=2) return n+1;
	    if(dp[n]!=-1) return dp[n];
	    return dp[n]=(countStrings(n-1)%m+countStrings(n-2)%m)%m;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends