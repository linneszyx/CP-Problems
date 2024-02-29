//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
#define ll long long
class Solution{
public:
	long long f(int arr[],int n){
	    unordered_map<ll,ll> mp;
	    for(int i=0;i<n;i+=1) {ll num = arr[i];
	    for(ll i=0;i<31;i+=1){
	        if(num&(1<<i)) mp[i]++;
	    }}
	    ll ans = 0;
	    for(ll i=0;i<31;i+=1){
	        ll setc= mp[i];
	        ll off = long(n) - setc;
	        ans+=off*setc;
	    }
	    ans*=2;
	    return ans;
	}
	long long sumBitDifferences(int arr[], int n) {
	    // code here
	    ll ans = f(arr,n);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends