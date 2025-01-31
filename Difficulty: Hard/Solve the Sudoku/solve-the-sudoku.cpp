//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define vvi vector<vector<int>>
class Solution {
  public:
  bool ff(vvi &mat,int x,int r,int c){
      for(int i=0;i<9;i+=1) {
          if(mat[r][i]==x || mat[i][c]==x) return false;
      }
      int sr = r-(r%3);
      int sc = c-(c%3);
      for(int i=sr;i<sr+3;i+=1) {
          for(int j=sc;j<sc+3;j+=1) {
              if(mat[i][j]==x) return false;
          }
      }
      return true;
  }
  bool f(vvi &mat,int r,int c) {
      if(r==9) return true;
      if(mat[r][c]!=0) return f(mat,r,c+1);
      if(c==9) return f(mat,r+1,0);
      for(int x=1;x<=9;x+=1) {
          if(!ff(mat,x,r,c)) continue;
          mat[r][c]=x;
          if(f(mat,r,c+1)) return true;
          mat[r][c]=0;
      }
      return false;
  } 
    void solveSudoku(vvi &mat) {
        f(mat,0,0);
    }
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends