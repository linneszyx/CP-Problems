//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    public:
    int xa[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int ya[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int n, m;

    bool dfs(vector<vector<char>>& board, string& s, int x, int y, int idx) {
        if (idx == s.length()) return true;
        char c=board[x][y];
       board[x][y]='*';
        for (int i = 0; i < 8; i++) {
            int x_ = x + xa[i];
            int y_ = y + ya[i];
            if (x_ >= 0 && x_ < n && y_ >= 0 && y_ < m && s[idx] == board[x_][y_] ) {
                if (dfs(board, s, x_, y_, idx + 1)) {
                       board[x][y]=c;  
                    return true;
                }
                
            }
        }
         board[x][y]=c;
     
        return false;
    }

    vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dict) {
        n = board.size();
        m = board[0].size();
        bool flag = false;
        int k = dict.size();
        vector<string> ans;
        unordered_set<string> st;
    
        for (int i = 0; i < k; i++) {
            string s = dict[i];
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    if (board[j][k] == s[0]) {
                      
                        flag = dfs(board, s, j, k, 1);
                    }
                    if (flag) {
                     
                        st.insert(s);
                        flag = false;
                        
                    }
                }
            }
        }
       for(auto &x:st){
           ans.push_back(x);
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends