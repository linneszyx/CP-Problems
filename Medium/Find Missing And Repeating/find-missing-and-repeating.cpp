//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
       vector<int>result;int j;int HASH[n+1]={0};int repeat =0;int missing=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
        {
            HASH[arr[i]]++;
            
        }
        
        for(int i=0;i<n+1;i++)
        {
            if(HASH[i] > 1)
            {
                repeat = i;
            }
        }
        
        for(int i=1;i<n+1;i++)
        {
            if(HASH[i] == 0)
            {
                missing = i;
            }
        }
        
        return {repeat,missing};
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
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends