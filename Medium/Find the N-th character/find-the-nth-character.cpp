//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
        for(int i=0;i<r;i+=1) {
            int len = s.size();
            string temp = "";
            for(int j=0;j<len;j+=1){
                if(s[j]=='1') temp+="10";
                else temp+="01";
                if(j>=n) break;
            }
            s=temp;
        }
        return s[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends