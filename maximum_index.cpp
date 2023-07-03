//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            if(s.empty()) s.push(i);
            else if(arr[i]>arr[s.top()]) s.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[i]<=arr[s.top()]){
                ans=max(ans,s.top()-i);
                s.pop();
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
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends