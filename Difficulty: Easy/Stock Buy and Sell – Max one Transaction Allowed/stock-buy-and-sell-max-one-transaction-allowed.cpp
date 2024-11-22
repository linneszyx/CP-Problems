//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define forn(i,e) for(int i=0;i<e;i+=1)
#define sz(x) ((int) x.size())
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int mp = 0;
        int mini = prices[0];
        int n = sz(prices);
        forn(i,n) {
            if(prices[i]<mini) {
                mini = prices[i];
            }
            mp = max(mp,prices[i]-mini);
        }
        return mp;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends