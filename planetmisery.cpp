int planetMisery(int n, int m)
{
    vector<int> dp(m + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int prev = 0;
        for (int j = 1; j <= m; j++)
        {
            int temp = dp[j];
            dp[j] = max(dp[j], dp[j - 1]) + 1;
            prev = temp;
        }
    }
    return dp[m];
}