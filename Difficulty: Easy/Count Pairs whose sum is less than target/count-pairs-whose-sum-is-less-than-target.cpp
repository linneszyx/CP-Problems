//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
#define sz(x) ((int)x.size())
#define all(p) p.begin(),p.end()
class Solution {
  public:
    int countPairs(vector<int> &arr, int tar) {
        int n = sz(arr);
        if(n<2) return 0;
        if((n==2) and (arr[0]+arr[1]==tar)) return 1;
        sort(all(arr));
        int s=0,e=n-1,c=0;
        while(s<e) {
            while((arr[s]+arr[e]>=tar) and (s<e)) e--;
            int l = e-s;
            c+=l;
            s++;
        }
        return c;
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
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends