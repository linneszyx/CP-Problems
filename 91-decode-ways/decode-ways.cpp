#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    string s;
    int n;
    vector<int> dp;
    int f(int i){
        if (i==n) return 1;
        if (dp[i]!=-1) return dp[i];
        if (s[i]=='0') return dp[i]=0;
        int ans=f(i+1);
        if ( i+1<n && (s[i]=='1'|| (s[i]=='2' && s[i+1]<='6'))){
            ans+=f(i+2);
        }
        return dp[i]=ans;
    }
    int numDecodings(string& s) {
        if (s[0]=='0') return 0;
        this->s=s;
        n=s.size();
        dp.assign(n+1, -1);
        return f(0);
    }
};