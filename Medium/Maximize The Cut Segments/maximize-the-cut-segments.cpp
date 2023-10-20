//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
 int solve(int amount,int x,int y,int z,vector<int> &dp)
  {
     if(amount==0)return 0;
     if(amount<0)return INT_MIN;
     
     if(dp[amount]!=-1)return dp[amount];
     
     int a=solve(amount-x,x,y,z,dp);
       int b=solve(amount-y,x,y,z,dp);
         int c=solve(amount-z,x,y,z,dp);
         
         return dp[amount]=1+max(a,max(b,c));
  }
 
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
       
       vector<int> dp(n+1,-1);
      int a=solve(n,x,y,z,dp);
      if(a<0)return 0;
      return a;
     
        
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends