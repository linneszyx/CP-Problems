//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        // code here
        int n = S.size();
        string res = "";
        int maxLen = 0;
        for(int i = 0; i < n; i++) {
            int l = i, r = i;
            while(l >= 0 && r < n && S[l] == S[r]) {
                if(r - l + 1 > maxLen) {
                    maxLen = r - l + 1;
                    res = S.substr(l, maxLen);
                }
                l--;
                r++;
            }
            l = i, r = i + 1;
            while(l >= 0 && r < n && S[l] == S[r]) {
                if(r - l + 1 > maxLen) {
                    maxLen = r - l + 1;
                    res = S.substr(l, maxLen);
                }
                l--;
                r++;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends