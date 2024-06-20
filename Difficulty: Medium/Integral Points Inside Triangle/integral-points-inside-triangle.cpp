//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define ll long long 
class Solution {
  public:
    long long int InternalCount(long long int p[], long long int q[],
                                long long int r[]) {
        // code here
        ll ar = abs(p[0]*(q[1]-r[1])+q[0]*(r[1]-p[1])+r[0]*(p[1]-q[1]))/2;
        ll bp1 = __gcd(abs(p[0]-q[0]),abs(p[1]-q[1]))+1;
        ll bp2 = __gcd(abs(p[0]-r[0]),abs(p[1]-r[1]))+1;
        ll bp3 = __gcd(abs(r[0]-q[0]),abs(r[1]-q[1]))+1;
        ll B = bp1+bp2+bp3-3;
        ll I = (ar-B/2+1);
        return I;
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int p[2], q[2], r[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1];
        Solution ob;
        long long int ans = ob.InternalCount(p, q, r);
        cout << ans << "\n";
    }
}
// } Driver Code Ends