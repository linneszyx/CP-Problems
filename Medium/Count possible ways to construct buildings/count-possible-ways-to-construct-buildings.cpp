//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long
class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	    int mod = 1e9 + 7;
	    int prev1 = 2;
	    int prev2 = 3;
	    if(N == 1) return prev1*prev1;
	    if(N == 2) return prev2*prev2;
	    for(int i = 3; i <= N; i++) {
	        int curr = (prev1 + prev2)%mod;
	        prev1 = prev2;
	        prev2 = curr;
	    }
	    return (static_cast<ll> (prev2)*prev2)%mod;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends