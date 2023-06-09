/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res = letters[0];
        for (char c : letters) {
            if (c > target) {
                res = c;
                break;
            }
        }
        return res;
    }
};
// @lc code=end

