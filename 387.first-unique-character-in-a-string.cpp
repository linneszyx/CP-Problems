/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (59.19%)
 * Likes:    7329
 * Dislikes: 250
 * Total Accepted:    1.3M
 * Total Submissions: 2.3M
 * Testcase Example:  '"leetcode"'
 *
 * Given a string s, find the first non-repeating character in it and return
 * its index. If it does not exist, return -1.
 *
 *
 * Example 1:
 * Input: s = "leetcode"
 * Output: 0
 * Example 2:
 * Input: s = "loveleetcode"
 * Output: 2
 * Example 3:
 * Input: s = "aabb"
 * Output: -1
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s consists of only lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int firstUniqChar(string s)
    {
      int n = s.size();
      for (int i = 0; i < n; i++)
      {
        int flag = 1;
        for(int j =0 ;j<n;j++){
            if(i!=j and s[i]==s[j]) {
                flag = 0;
                break;
            }
        }
        if(flag==1){
            return i;
        }
      }
      return -1;
      
      
    }
};
// @lc code=end
