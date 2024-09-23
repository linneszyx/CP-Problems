//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
          int n = arr.size();
        vector<int> x(n+1, 0);
        
        for(int i = 0; i < n; i++) {
            int ele = arr[i];
            x[ele]++;
        }
        
        vector<int> ans(2, -1); 
        
        for(int i = 1; i <= n; i++) {
            if(x[i] > 1) {
                ans[0] = i;  
            }
            if(x[i] == 0) {
                ans[1] = i;  
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends