//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#define vpp vector<pair<int,int>>
#define vii vector<vector<int>>
void f(vii &mat,vpp &rc)
{
    for(int i=0;i<mat.size();i+=1) {
        for(int j=0;j<mat[i].size();j+=1) {
            if(mat[i][j]==0) rc.push_back(make_pair(i,j));
        }
    }
}
void fr(vii &mat,int r) {
    fill(mat[r].begin(),mat[r].end(),0);
}
void fc(vii &mat,int c) {
    for(int j=0;j<mat.size();j+=1) mat[j][c]=0;
}
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        vpp rc;
        f(mat,rc);
        for(int i=0;i<rc.size();i+=1) {
            fc(mat,rc[i].second);
            fr(mat,rc[i].first);
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends