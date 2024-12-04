//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define sz(x) ((int)x.length())
#define vi vector<int>
class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        int n1=sz(s1),n2=sz(s2);
        if(n1!=n2) return false;
        string s = s2+"$"+s1+s1;
        int n = sz(s);
        vi v(n,0);
        int i=1,len=0;
        while(i<n) {
            if(s[i]==s[len]) {
                len++;
                v[i]=len;
                i++;
            }
            else {
                if(len>0) len=v[len-1];
                else i++;
            }
        }
        for(int x : v) {
            if(x==n1) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) {
            cout << "true" << endl;

        } else {
            cout << "false" << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends