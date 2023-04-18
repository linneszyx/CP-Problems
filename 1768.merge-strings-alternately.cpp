/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */

// @lc code=start
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        int n = min(n1, n2);
        string res;
        for (int i = 0; i < n; i++) {
            res.push_back(word1[i]);
            res.push_back(word2[i]);
        }
        if (n1 > n) {
            res += word1.substr(n);
        }
        if (n2 > n) {
            res += word2.substr(n);
        }
        return res;
    }
};
// @lc code=end

