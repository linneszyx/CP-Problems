//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
      vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_map<int ,vector<int>> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int s = i+j;
                mp[s].push_back(matrix[i][j]);
            }
        }
        int k=0;
        while(mp.find(k) != mp.end()){
            for(auto it:mp[k]){
                ans.push_back(it);
            }
            k++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends