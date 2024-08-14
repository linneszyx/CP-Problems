//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        int size = 0;
    for(int i = 0; i<str1.size(); i++){
        for(int j = 1; j<=str1.size()-i; j++){
            string ans = str1.substr(i,j);
            if(str2.find(ans) != string::npos){
                if(size<j){
                    size = j;
                }
            }else{
                break;
            }
        }
      }
    return size;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends