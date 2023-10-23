//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> arr)
    {
        int t[n+1][n+2];
        for(int i=0; i<=n ;i++)
        {
             t[i][0]=0;
             t[i][n+1]=0;
        }
        for(int i=1; i<=n ;i++)
        {
             t[0][i]=0;
        }
        for(int i=1; i<=n ;i++)
        {
            for(int j=1; j<=n ;j++)
            {
                 t[i][j]=arr[i-1][j-1]+max(t[i-1][j],max(t[i-1][j+1],t[i-1][j-1]));
            } 
        }
        int ans=0;
        for(int i=1; i<=n ;i++)
        {
             ans=max(ans,t[n][i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends