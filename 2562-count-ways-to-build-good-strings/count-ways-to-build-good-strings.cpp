class Solution {
public:
    vector<int> dp;
    const int mod = 1e9+7;
    int solve(int low,int high,int zero,int one,int str){
        if(str>high) return 0;
        if(dp[str]!=-1) return dp[str];
        return dp[str] = ((str>=low) +solve(low,high,zero,one,str+zero)%mod+solve(low,high,zero,one,str+one)%mod)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        dp.resize(100002,-1);
        return solve(low,high,zero,one,0);
    }
};