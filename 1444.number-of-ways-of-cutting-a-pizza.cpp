/*
 * @lc app=leetcode id=1444 lang=cpp
 *
 * [1444] Number of Ways of Cutting a Pizza
 */

// @lc code=start
class Solution
{
private:
    /* 1. `static constexpr int kMod = 1'000'000'007;` is a constant that is used to mod the answer.
    2. `vector<vector<vector<int>>> dp;` is a 3D array that is used to store the answer.
    3. `vector<vector<int>> sum;` is a 2D array that is used to store the sum of the number of apples
    in a submatrix. */
    static constexpr int kMod = 1'000'000'007;
    vector<vector<vector<int>>> dp;
    vector<vector<int>> sum;

public:
    int ways(vector<string> &pizza, int k)
    {
        /* Creating a 2D array of size MxN and filling it with -1. */
        const int M = pizza.size();
        const int N = pizza[0].size();
        dp.resize(M, vector<vector<int>>(N, vector<int>(k, -1)));
        sum.resize(M + 1, vector<int>(N + 1));
        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + (pizza[i][j] == 'A');
            }
        }
        return dfs(0, 0, k - 1, M, N);
    }
    int dfs(int m, int n, int k, const int M, const int N)
    {
        /* The base case. */
        if (k == 0)
        {
            return 1;
        }
        /* A memoization. */
        if (dp[m][n][k] > 0)
        {
            return dp[m][n][k];
        }
        dp[m][n][k] = 0;
        /* Checking if there is a row that has apple on both sides. */
        for (int i = m + 1; i < M; ++i)
        {
            if (containApples(m, i, n, N) and containApples(i, M, n, N))
            {
                dp[m][n][k] = (dp[m][n][k] + dfs(i, n, k - 1, M, N)) % kMod;
            }
        }
        /* Checking if there is a column that has apple on both sides. */
        for (int j = n + 1; j < N; ++j)
        {
            if (containApples(m, M, n, j) and containApples(m, M, j, N))
            {
                dp[m][n][k] = (dp[m][n][k] + dfs(m, j, k - 1, M, N)) % kMod;
            }
        }
        return dp[m][n][k];
    }
    bool containApples(int r1, int r2, int c1, int c2)
    {
        return sum[r2][c2] - sum[r2][c1] - sum[r1][c2] + sum[r1][c1] > 0;
    }
};
// @lc code=end
