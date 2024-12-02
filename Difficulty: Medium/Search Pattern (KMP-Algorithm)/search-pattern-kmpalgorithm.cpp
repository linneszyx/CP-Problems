//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define vi vector<int>
#define pb push_back
class Solution {
  public:
    vector<int> search(string& pat, string& txt) {
        vi v;
        int x = pat.length();
        int y = txt.length();
        for(int i=0;i<y-x+1;i+=1) {
          if(pat[0]!=txt[i]) continue;
          string str = txt.substr(i,x);
          if(str==pat) v.pb(i);
        }
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends