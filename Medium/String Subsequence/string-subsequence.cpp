//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  const int MOD = 1e9 + 7;

int Ans(int index1, int index2, string &str1, string &str2, vector<vector<int>>& dp) {
    if (index2 < 0) {
        return 1;
    }
    if (index1 < 0) {
        return 0;
    }
    if (dp[index1][index2] != -1) {
        return dp[index1][index2] % MOD;
    }
    if (str1[index1] == str2[index2]) {
        return dp[index1][index2] = (Ans(index1 - 1, index2 - 1, str1, str2, dp) % MOD + Ans(index1 - 1, index2, str1, str2, dp) % MOD) % MOD;
    }
    return dp[index1][index2] = Ans(index1 - 1, index2, str1, str2, dp) % MOD;
}

int countWays(string &str1, string &str2) {
    int len1 = str1.length();
    int len2 = str2.length();
    
    vector<vector<int>> dp(len1, vector<int>(len2, -1));
    return Ans(len1 - 1, len2 - 1, str1, str2, dp) % MOD;
}


};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends