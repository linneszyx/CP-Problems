//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int numberOfConsecutiveOnes(int n) {
        if(n==2)
            return 1;
        int ans = 1, a = 0, b = 1;
        int mod = 1e9+7;
        for(int i = 3; i <= n; i++)
        {
            int c = (a + b)%mod;
            ans = ((ans*2)%mod + c)%mod;
            a = b%mod;
            b = c%mod;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends