//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution{
    bool solve(int windex,int pindex,string wild,string pattern,vector<vector<int>>&dp){
        
        if(windex<0 and pindex<0){//both the wild and pattern has matched completly and ended simulatenously
            return true;
        }
        
        else if(windex<0 and pindex>=0){//wildcard has been ended but pattern is still left
        //we need to match  the patetrn to wild card
            return false;
        }
        else if(windex>=0 and pindex<0){
            //means pattern has been matched complately
            //so in wild cards only starsrs hould be there
            //starts can only be replaced by empty characyers
            for(int k=0;k<=windex;k++){
                if(wild[k]!='*'){
                    return false;
                }
                
            }
            return true;
        }
        
        //if already calculated
        if(dp[windex][pindex]!=-1){
            return dp[windex][pindex];
        }
        //case 1:if charcaters at both wild card and pattrn are same or wild card contains ? mark
        if(wild[windex]==pattern[pindex]||wild[windex]=='?'){
            return dp[windex][pindex]= solve(windex-1,pindex-1,wild,pattern,dp);
        }
        //case2:if wild card conatisn* 
        //in this case we cqn replace the star by blank or keep the matching characters here and keep the windex at * for matching the sequnce of characters
        
        else if(wild[windex]=='*'){
            return dp[windex][pindex]=solve(windex,pindex-1,wild,pattern,dp)||solve(windex-1,pindex,wild,pattern,dp);
        }
        
        
        
        
    }
    public:
    bool match(string wild, string pattern)
    
    {
        int n=wild.size(),m=pattern.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        dp[0][0]=1;
        
        for(int i=1;i<=n;i++){
            bool temp=true;
            for(int k=1;k<=i;k++){
                if(wild[k-1]!='*'){
                   temp=false;
                   break;
                }
            }
            dp[i][0]=temp?1:0;
            
        }
        
      for(int j=1;j<=m;j++){
          dp[0][j]=0;
      }
      
      
      for(int i=1;i<=n;i++){
          for(int j=1;j<=m;j++){
              
              
        if(wild[i-1]==pattern[j-1]||wild[i-1]=='?'){
             dp[i][j]= dp[i-1][j-1];
        }
        
        if(wild[i-1]=='*'){
            dp[i][j]=dp[i-1][j]||dp[i][j-1];
        }
        
        
    }
}

return dp[n][m];
      
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends