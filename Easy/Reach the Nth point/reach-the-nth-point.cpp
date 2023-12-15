//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		const int MOD = 1e9 + 7;

int nthPoint(int n){
    int p1 = 1, p2 = 0;
    for(int i=1; i<=n; i++) {
        int curr = (p1 + p2) % MOD;
        p2 = p1;
        p1 = curr;
    }
   return p1 % MOD;
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends