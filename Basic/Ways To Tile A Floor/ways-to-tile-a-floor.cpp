//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long
const int mod = 1e9+7;
class Solution {
  public:
    long long numberOfWays(long long N) {
        //code here
       ll dp[N+1];
       dp[0] = 1;
       dp[1] = 1;
       for(int i=2;i<=N;i++){
           dp[i]=(dp[i-1]+dp[i-2])%mod;
       }
       return dp[N];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.numberOfWays(N) << endl;
    }
    return 0;
}
// } Driver Code Ends