//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(auto it : edges) {
            dp[it[0]][it[1]]=it[2];
            dp[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i+=1) dp[i][i]=0;
        for(int k=0;k<n;k+=1) {
            for(int i=0;i<n;i+=1){
                for(int j=0;j<n;j+=1){
                    if(dp[i][k]== INT_MAX or dp[k][j]==INT_MAX) continue;
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
                 }
            }
        }
        int cntCity = n;
        int cityNo = -1;
        for(int c=0;c<n;c+=1){
            int cnt = 0;
            for(int ac = 0;ac<n;ac+=1){
                if(dp[c][ac]<=distanceThreshold) cnt++;
            }
            if(cnt<=cntCity) {
                cntCity=cnt;
                cityNo = c;
            }
        }
        return cityNo;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends