//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
           priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; 
        // priority_queue <int, vector<int>, greater<int>> gq;
        
        vector<vector<int>>dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}} ;
        pq.push({0, 0, 0}); 
        while(!pq.empty()){
            vector<int>curr = pq.top(); 
            pq.pop(); 
            int h = curr[0]; 
            int x = curr[1]; 
            int y = curr[2]; 
            
            if (x == X and y == Y)
                return h; 
            A[x][y] = -1; 
            
            for(int i = 0; i < 4; i++){
                int m = x + dir[i][0]; 
                int n = y + dir[i][1]; 
                
                if(m >=  0 and n >= 0 and m < N and n < M and A[m][n] == 1 and A[m][n] != -1) {
                    A[m][n] = -1; 
                    pq.push({h + 1, m, n}); 
                }
            }
        }
        return -1;  
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends