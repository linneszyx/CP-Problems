//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(vector<int> &arr) {
        int mx=arr[0],cur=arr[0];
        int n = arr.size();
        for(int i=1;i<n;i+=1) {
            cur=max(arr[i],cur+arr[i]);
            mx=max(mx,cur);
        }
        return mx;
    }
    int circularSubarraySum(vector<int> &arr) {
    int n = arr.size();
    int mx=f(arr);
    if(mx<0) return mx;
    int s=0;
    for(int i=0;i<n;i+=1) {
        s+=arr[i];
        arr[i]=-arr[i];
    }
    int mii = f(arr);
    int mxi = s+mii;
    return max(mxi,mx);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends