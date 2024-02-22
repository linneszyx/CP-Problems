//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

const int mod = 1e9+7;
class Solution
{   
    public:
    int dp[1005][1005];
    int f(int ci,int cti,string &s,string &t){
        if(cti==0) return 1;
        if(ci==0) return 0;
        if(dp[ci-1][cti-1]!=-1) return dp[ci-1][cti-1];
        long long r1 = 0;
        if(s[ci-1]==t[cti-1]) r1=(r1+f(ci-1,cti-1,s,t))%mod;
        r1=(r1+f(ci-1,cti,s,t))%mod;
        return dp[ci-1][cti-1]=r1;
    }
    int subsequenceCount(string s, string t)
    {
      //Your code here
      memset(dp,-1,sizeof(dp));
    int ci = s.length(),cti=t.length();
    return f(ci,cti,s,t);
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends