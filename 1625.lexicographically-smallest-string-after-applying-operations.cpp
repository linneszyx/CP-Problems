/*
 * @lc app=leetcode id=1625 lang=cpp
 *
 * [1625] Lexicographically Smallest String After Applying Operations
 */

// @lc code=start
class Solution
{
public:
    bool compare(string &s, string &t)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] < t[i])
                return true;
            else if (s[i] > t[i])
                return false;
        }
        return false;
    }
    string findLexSmallestString(string s, int a, int b)
    {
        string ans = s;
        set<string> seen;
        queue<string> q;
        q.push(s);
        while (!q.empty())
        {
            string curr = q.front();
            q.pop();
            if (seen.find(curr) != seen.end())
                continue;
            seen.insert(curr);
            if (compare(curr, ans))
                ans = curr;
            string add = curr.substr(curr.size() - b) + curr.substr(0, curr.size() - b);
            q.push(add);
            for (int i = 1; i < curr.size(); i += 2)
            {
                curr[i] = (curr[i] - '0' + a) % 10 + '0';
            }
            q.push(curr);
        }
        return ans;
        
    }
};
// @lc code=end
