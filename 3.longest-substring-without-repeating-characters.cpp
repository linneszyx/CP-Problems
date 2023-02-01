/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> ch;
        int l = 0;
        int r = 0;
        int n = s.length();
        int ans = 0;
        while(r<n){
            char x = s[r];
            ch[x]++;
            while (ch[x]>1)
            {
                char z = s[l];
                ch[z]--;
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
// @lc code=end

