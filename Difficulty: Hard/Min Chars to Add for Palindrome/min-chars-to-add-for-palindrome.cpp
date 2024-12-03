//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minChar(string& s) {
        string res = s;
        reverse(res.begin(),res.end());
        s+="$";
        s+=res;
        int n = s.length();
        int pre=0,suff=1;
        vector<int> v(n,0);
        while(suff<n) {
            if(s[suff]==s[pre]) {
                v[suff]=pre+1;
                suff++;
                pre++;
            }
            else {
                if(pre==0) suff++;
                else pre=v[pre-1];
            }
        }
        return res.length()-v[n-1];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends