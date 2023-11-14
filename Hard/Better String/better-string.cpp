//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   long long fun(string &s){
        vector<int>vis(26,-1);
        int n=s.size();
        vector<long long>dp(n+1,1);
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1]*1ll*2;
            if(vis[s[i-1]-'a']!=-1){
                dp[i]=(dp[i]-dp[vis[s[i-1]-'a']]);
            }
            vis[s[i-1]-'a']=i-1;
        }
        return dp[n];
    }
    string betterString(string str1, string str2) {
        return fun(str1)>=fun(str2)?str1:str2;
     }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends