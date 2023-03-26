/*
 * @lc app=leetcode id=1328 lang=cpp
 *
 * [1328] Break a Palindrome
 */

// @lc code=start
class Solution
{
public:
    string breakPalindrome(string palindrome)
    {
        int n = palindrome.size();
        if (n == 1)
        {
            return "";
        }
        vector<vector<int>> res(26);
        int firstNonA = -1;
        for (int i = 0; i < n; i++)
        {
            res[palindrome[i] - 'a'].push_back(i);
            if (palindrome[i] != 'a' && firstNonA == -1)
            {
                firstNonA = i;
            }
        }
        if (res[0].size() >= n - 1)
        {
            palindrome[res[0].back()] = 'b';
        }
        else
        {
            palindrome[firstNonA] = 'a';
        }
        return palindrome;
    }
};
// @lc code=end
