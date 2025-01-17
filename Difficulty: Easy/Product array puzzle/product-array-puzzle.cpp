//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
#define sz(x) ((int)x.size())
#define vi vector<int>
class Solution {
  public:
    vi productExceptSelf(vi& arr) {
        int n = sz(arr);
        vi v(n,1);
        for(int i=1;i<n;i+=1) v[i]=v[i-1]*arr[i-1];
        int s=1;
        for(int i=n-2;i>=0;i-=1) {
            s*=arr[i+1];
            v[i]=v[i]*s;
        }
        return v;
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
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends