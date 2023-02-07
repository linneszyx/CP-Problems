/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 *
 * https://leetcode.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (57.81%)
 * Likes:    3621
 * Dislikes: 400
 * Total Accepted:    695K
 * Total Submissions: 1.2M
 * Testcase Example:  '"a"\n"b"'
 *
 * Given two strings ransomNote and magazine, return true if ransomNote can be
 * constructed by using the letters from magazine and false otherwise.
 *
 * Each letter in magazine can only be used once in ransomNote.
 *
 *
 * Example 1:
 * Input: ransomNote = "a", magazine = "b"
 * Output: false
 * Example 2:
 * Input: ransomNote = "aa", magazine = "ab"
 * Output: false
 * Example 3:
 * Input: ransomNote = "aa", magazine = "aab"
 * Output: true
 *
 *
 * Constraints:
 *
 *
 * 1 <= ransomNote.length, magazine.length <= 10^5
 * ransomNote and magazine consist of lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int count = 0;
        int ransom_size = ransomNote.length();
        int magazine_size = magazine.length();
        for (int i = 0; i < ransom_size; i++)
        {
            for (int j = 0; j < magazine_size; j++)
            {
                count = 0;
                if (magazine[j] == ransomNote[i])
                {
                    count++;
                    magazine[j]=64;
                    break;
                }
            }
            if(count==0){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
