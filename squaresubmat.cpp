#include <bits/stdc++.h>
int largestSquareSubmatrix(vector<vector<int>> &mat, int n, int m, int k)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = mat[i][0];
        if (dp[i][0] <= k)
            ans = 1;
    }
    for (int i = 0; i < m; i++)
    {
        dp[0][i] = mat[0][i];
        if (dp[0][i] <= k)
            ans = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
            if (mat[i][j] == 1)
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                if (dp[i][j] <= k)
                ans = max(ans, dp[i][j]);
            }
    }
    return ans;
}
