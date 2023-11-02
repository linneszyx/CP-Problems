//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
long long int f(int i){
    if(i<=6) return i;
    vector<long long int> dp(i+1,-1);
    for(int i=0;i<=6;i+=1) dp[i] = i;
    for(int k=7;k<=i;k+=1){
        long long int maxi = INT_MIN;
        for(int j=k-3;j>=1;j-=1){
            maxi = max(maxi,dp[j]*(k-j-2+1));
        }
        dp[k] = maxi;
    }
    return dp[i];
}
    long long int optimalKeys(int N){
        // code here
        return f(N);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends