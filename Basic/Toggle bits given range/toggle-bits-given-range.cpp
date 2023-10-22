//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int toggleBits(int N , int L , int R) {
         int ans=N;
        int dup=0;
        for(int i=(L-1);i<=(R-1);i++){
            dup=1<<i;
            ans=ans^dup;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,L,R;
        
        cin>>N>>L>>R;

        Solution ob;
        cout << ob.toggleBits(N,L,R) << endl;
    }
    return 0;
}
// } Driver Code Ends