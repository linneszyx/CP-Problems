/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (43.42%)
 * Likes:    5385
 * Dislikes: 11272
 * Total Accepted:    946.5K
 * Total Submissions: 2.1M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "A", numRows = 1
 * Output: "A"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * s consists of English letters (lower-case and upper-case), ',' and '.'.
 * 1 <= numRows <= 1000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<2) {
            return s;
        }
        int ts[numRows][s.size()];
        memset(ts,-1,sizeof(ts));
        for(int i=0,ch=1,r=0;i<s.size();i++){
            ts[r][i] = s[i];
            if(r==numRows-1) ch = -1;
            if(r==0) ch = 1;
            r = r+ch;
        }
        string res;
        for(int i=0;i<numRows;i++){
            for(int j=0;j<s.size();j++){
                if(ts[i][j]!=-1) {
                    res.push_back(ts[i][j]);
                }
            }
        }
        return res;
    }
};
// @lc code=end

