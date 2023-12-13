
class Solution {
public:
    bool solve(int i,int j,string &s,string &p,vector<vector<int>>&dp){
        if(dp[i][j]!=-1)
            return dp[i][j];

        if(i>=s.length() and j>=p.length())
            return true;

        if(j>=p.length())               //p khatam ho gya hai and s bachi hai 
            return false;
        
        bool match= (i<s.length()) and (s[i]==p[j] or p[j]=='.');  //Matching the first char of both string 

        //Agar j wale character ke baad * hai to hmari choice hai ki uss j wale char ko use kare yaa naa kare 
        // Agar nhi kiya to j=j+2 
        // Agar karna hai to condition yeh hai ki p[j]==s[i] tab hi hm i=i+1 karenge 
    
        if((j+1)<p.length() and (p[j+1]=='*')){
            return dp[i][j]= ((match and solve(i+1,j,s,p,dp))  /* use  */  
                        or solve(i,j+2,s,p,dp) );              /* don't use */ 
        }

        if(match)      //When p[j+1]!="*" but Char at i and j matched so increment each of the string by 1
            return dp[i][j]=solve(i+1,j+1,s,p,dp);     

        return dp[i][j]=false;
    }


    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        // return solve(s,p,n,m,dp);

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,s,p,dp);
    }
};

    