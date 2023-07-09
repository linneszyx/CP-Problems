/*
 * @lc app=leetcode id=2272 lang=cpp
 *
 * [2272] Substring With Largest Variance
 */

// @lc code=start
class Solution
{
public:
    int largestVariance(string s)
    {
        int n = s.size();
        int res = 0;
        for (char p = 'a'; p <= 'z'; p++)
        {
            for (char q = 'a'; q <= 'z'; q++)
            {
                if (p == q)
                    continue;
                int pc = 0;
                int qc = 0;
                bool canextend = false;
                for (auto c : s)
                {
                    if (c == p)
                        pc++;
                    if (c == q)
                        qc++;
                    if (qc > 0)
                        res = max(res, pc - qc);
                    else if (qc == 0 and canextend)
                        res = max(res, pc - 1);
                    if (qc > pc)
                    {
                        qc = pc = 0;
                        canextend = true;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
