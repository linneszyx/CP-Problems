//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
         queue<pair<pair<int, int>, int>> q;
        int rows = grid.size();
        int cols = grid[0].size();
        int count_of_one = 0;
        /* This is to count the number of 1's in the grid. */
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 2)
                    q.push({{i, j}, 0});
                if(grid[i][j] == 1)
                    count_of_one++;
            }
        }
        if(count_of_one == 0) return 0;
        if(q.empty()) return -1;
        /* This is to create a copy of the grid. */
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                visited[i][j] = grid[i][j];
            }
        }
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        int time = 0;
       /* This is the BFS part. */
        while(!q.empty())
        {
            pair<pair<int, int>, int> p = q.front();
            q.pop();
            pair<int, int> index = p.first;
            time = p.second;

            for(int i = 0; i < 4; i++)
            {
                int newRow = delRow[i] + index.first;
                int newCol = delCol[i] + index.second;

               /* This is to check if the newRow and newCol are within the grid and if the newRow and
               newCol are not visited and not rotten. */
                if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && visited[newRow][newCol] != 2 && visited[newRow][newCol] != 0)
                {
                    q.push({{newRow, newCol}, time+1});
                    visited[newRow][newCol] = 2;
                }
            }
        }
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0;  j < cols; j++)
            {
                if(visited[i][j] == 1)
                    return -1;
            }
        }
        return time;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends