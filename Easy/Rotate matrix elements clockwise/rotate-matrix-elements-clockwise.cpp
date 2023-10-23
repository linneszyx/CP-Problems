//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int M, int N, vector<vector<int>> Mat) {
             int k=0,lim=min(M/2,N/2);
  while(k<lim){         
      for(int i=k+1;i<N;i++) swap(Mat[k][k],Mat[k][i]);
      for(int i=k+1;i<M;i++) swap(Mat[k][k],Mat[i][N-1]);
      for(int i=N-2;i>=k;i--) swap(Mat[k][k],Mat[M-1][i]);
      for(int i=M-2;i>=k;i--) swap(Mat[k][k],Mat[i][k]);
      k++;
      M--;
      N--;
  }
  return Mat;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(N, M, Mat);
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}
// } Driver Code Ends