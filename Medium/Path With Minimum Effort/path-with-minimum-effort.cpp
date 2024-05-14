//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int dist[100][100];
    bool visited[100][100];
    const int INF = 1e9;
    struct table {
        int row, col, diff;
        
        bool operator<(const table& lhs)const {
            if(diff != lhs.diff){
                return diff > lhs.diff;
            }else if(row != lhs.row){
                return row > lhs.row;
            }
            return col > lhs.col;
        }
    };
    int dr[4] = {-1,0,1,0}, dc[4] = {0,1,0,-1};
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // code here
        priority_queue<table> Q;
        for(int i=0;i<rows;++i){
            for(int j=0;j<columns;++j){
                dist[i][j] = INF;
                visited[i][j] = false;
            }
        }
        dist[0][0] = 0;
        table k;
        k.diff = dist[0][0];
        k.row = 0;
        k.col = 0;
        Q.push(k);
        while(!Q.empty()){
            auto sr = Q.top().row, sc = Q.top().col, d = Q.top().diff;
            //printf("%d %d %d\n",sr,sc,d);
            Q.pop();
            if(visited[sr][sc]) continue;
            visited[sr][sc] = true;
            if(sr == rows-1 && sc == columns-1){
                return dist[sr][sc];
            }
            for(int x=0;x<4;++x){
                auto vr = sr + dr[x], vc = sc + dc[x];
                if(vr < 0 || vc < 0 || vr >= rows || vc >= columns) continue;
                int maxAb = max(d,abs(heights[sr][sc] - heights[vr][vc]));
                if(maxAb < dist[vr][vc]){
                    dist[vr][vc] = maxAb;
                    k.diff = dist[vr][vc];
                    k.row = vr;
                    k.col = vc;
                    Q.push(k);
                }
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends