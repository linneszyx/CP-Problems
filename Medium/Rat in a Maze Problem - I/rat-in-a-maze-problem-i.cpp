//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
       void solve(vector<vector<int>> &matrix, int n, vector<string>&res, string temp, int i, int j){
        if (i < 0 or j < 0 or i >= n or j >= n or matrix[i][j] == 0) {
            return;
        }

        if(i == n - 1 and j == n - 1){
            res.push_back(temp);
            return;
        }
        
        
        matrix[i][j] = 0;
        
        solve(matrix, n, res, temp + "D", i + 1, j);
        solve(matrix, n, res, temp + "R", i, j + 1);
        solve(matrix, n, res, temp + "U", i - 1, j);
        solve(matrix, n, res, temp + "L", i, j - 1);
        
        matrix[i][j] = 1;

    }
    
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>res;
        
        solve(m, n, res, "", 0 , 0);
        return res;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends