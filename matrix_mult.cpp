//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
         vector<vector<int>> dp(N,vector<int>(N,0));
        int i=0,j=1;
        while(j<N and i<N) {
            dp[i][j] = 0;
            i++;
            j++;
        }
        for(int k=2;k<N;k++){
            int i=0,j=k;
            while(i<N and j<N){
                int mini = INT_MAX;
                for(int x = i+1;x<j;x++){
                    int v = dp[i][x] + dp[x][j];
                    v+=arr[i]*arr[x]*arr[j];
                    mini = min(mini,v);
                }
                dp[i][j] = mini;
                i++;
                j++;
            }
        }
        return dp[0][N-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends