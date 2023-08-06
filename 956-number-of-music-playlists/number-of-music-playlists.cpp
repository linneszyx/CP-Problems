const int MOD = 1e9+7;
#define ll long long
#define vii vector<vector<int>>
class Solution {
public:
ll solve(int n,int goal,int k,vii &dp){
    if(n==0 and goal==0) return 1;
    if(n==0 or goal==0) return 0;
    if(dp[n][goal]!=-1) return dp[n][goal];
    ll pick=solve(n-1,goal-1,k,dp)*n;
    ll notpick=solve(n,goal-1,k,dp)*max(n-k,0);
    return dp[n][goal] = (pick+notpick)%MOD;
}
    int numMusicPlaylists(int n, int goal, int k) {
        vii dp(n+1,vector<int>(goal+1,-1));
        return solve(n,goal,k,dp);
    }
};