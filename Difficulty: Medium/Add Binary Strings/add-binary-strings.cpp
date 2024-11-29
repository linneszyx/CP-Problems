//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

#define sz(x) (x.size())
#define all(p) p.begin(),p.end()
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        string res="";
        int n = sz(s1),m = sz(s2),i=n-1,j=m-1,c=0;
        while(i>=0 or j>=0 or c) {
            int s=c;
            if(i>=0) s+=s1[i--]-'0';
            if(j>=0) s+=s2[j--]-'0';
            res+=(s%2)+'0';
            c=s/2;
        }
        reverse(all(res));
        int count=0;
        while(res[count]=='0') count++;
        res.erase(0,count++);
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends