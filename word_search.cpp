//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(vector<vector<char>>&board,string word,int i,int j,int k,int n,int m,int l){
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!=word[k]){
            return false;
        }
        if(k==l-1){
            return true;
        }
        char temp = board[i][j];
        board[i][j] = '*';
        bool res = dfs(board,word,i+1,j,k+1,n,m,l) || dfs(board,word,i-1,j,k+1,n,m,l) || dfs(board,word,i,j+1,k+1,n,m,l) || dfs(board,word,i,j-1,k+1,n,m,l);
        board[i][j] = temp;
        return res;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n = board.size();
        int m = board[0].size();
        int l = word.length();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,word,i,j,0,n,m,l)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends