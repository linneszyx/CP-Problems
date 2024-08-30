//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   vector<vector<string>> ans;
    bool valid(vector<string>&b , int r , int c){
        for(int i = r; i>= 0 ;i--) if(b[i][c] == 'Q') return false;
        for(int i = r , j = c ; i>=0 && j>= 0 ; i--, j--) if(b[i][j] == 'Q') return false;
        for(int i = r , j = c; i>= 0 && j < b.size(); i--, j++) if(b[i][j] == 'Q') return false;
        return true;
    }
    void dfs(vector<string> &b , int r){
        if(r == b.size()){
            ans.push_back(b);
            return;
        }
        for(int c = 0 ; c < b.size(); c++){
            if(valid(b , r , c)){
                b[r][c] = 'Q';
                dfs(b , r+1);
                b[r][c] = '.';
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<string> b(n , string(n , '.'));
        dfs(b , 0);
        vector<vector<int>> res;
        for(int i = 0 ; i< ans.size(); i++){
            vector<int> v;
            for(int j = 0 ; j< n; j++){
                for(int k = 0 ; k< n; k++){
                    if(ans[i][j][k] == 'Q'){
                        v.push_back(k+1);
                    }
                }
            }
            res.push_back(v);
        }
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends