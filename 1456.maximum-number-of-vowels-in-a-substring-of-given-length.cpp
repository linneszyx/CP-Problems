/*
 * @lc app=leetcode id=1456 lang=cpp
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 */

// @lc code=start
class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' ||
               c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i >= k && isVowel(s[i - k])) {
                --cnt;
            }
            if (isVowel(s[i])) {
                ++cnt;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
// @lc code=end

