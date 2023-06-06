//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        // code here
        vector<int> v;
        v.push_back(0);
        v.push_back(1);
        for (int i = 2; i <= n; i++) {
            if (i % 2 == 0)
                v.push_back(2);
            else
                v.push_back(i);
        }
        for (int i = 3; i * i <= n; i++) {
            if (v[i] == i) {
                for (int j = i * i; j <= n; j += i) {
                    if (v[j] == j)
                        v[j] = i;
                }
            }
        }
        return v;

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
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends