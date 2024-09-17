//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        if(arr.empty()) return 0;
        sort(arr.begin(),arr.end());
        int n =arr.size();
        int md = arr[n-1]-arr[0];
        for(int i=1;i<n;i+=1) {
            if(arr[i]<k) continue;
            int mv=min(arr[0]+k,arr[i]-k);
            int mx = max(arr[n-1]-k,arr[i-1]+k);
            md=min(md,mx-mv);
        }
        return md;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends