//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
          int n=mat.size();
        vector<int> ans;
        for(int i=0;i<2*n-1;i++){
            vector<int> temp;
            int l=0,r=i;
            if(i>=n){
                l=i-n+1,r=n-1;
            }
            while(l<n && r>=0){
                temp.push_back(mat[l][r]);
                l++; r--;
            }
            if(i%2==0){
                reverse(temp.begin(),temp.end());
            }
            for(int j=0;j<temp.size();j++){
                ans.push_back(temp[j]);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends