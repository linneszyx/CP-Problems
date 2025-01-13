//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

#define sz(x) ((int)x.size())
class Solution {

  public:
    int maxWater(vector<int> &arr) {
        int s=0,e=sz(arr)-1,mx=0;
        while(s<e) {
            int m = e-s;
            int h = min(arr[s],arr[e]);
            mx=max(mx,m*h);
            if(arr[s]<arr[e]) s++;
            else e--;
        }
        return mx;
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
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends