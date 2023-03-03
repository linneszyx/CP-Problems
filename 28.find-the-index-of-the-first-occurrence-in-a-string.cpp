/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0;
        int j = 0;
        int k = 0;
        int len = haystack.size();
        int len2 = needle.size();
        if (len2 == 0) {
            return 0;
        }
        while (i < len) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
                if (j == len2) {
                    return i - len2;
                }
            } else {
                i = i - j + 1;
                j = 0;
            }
        }
        return -1;
        
    }
};
// @lc code=end

