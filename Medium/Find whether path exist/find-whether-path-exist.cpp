//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    bool dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& visit){
        visit[i][j] = 1;
        
        int n = grid.size();
        int row[] = {0,1,-1,0};
        int col[] = {-1,0,0,1};
        
        for(int k=0;k<4;k++){
            int nr = i + row[k];
            int nc = j + col[k];
            
            if(nr<0 || nc<0 || nr>=n || nc>=n || grid[nr][nc]==0) continue;
            
            if(grid[nr][nc] == 2) return 1;
            
            if(grid[nr][nc] == 3 && !visit[nr][nc]){
                if(dfs(nr,nc,grid,visit)) return 1;
            }
        }
        return 0;
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<int>> visit(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    return dfs(i,j,grid,visit);
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends