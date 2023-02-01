/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 *
 * https://leetcode.com/problems/greatest-common-divisor-of-strings/description/
 *
 * algorithms
 * Easy (51.02%)
 * Likes:    2786
 * Dislikes: 428
 * Total Accepted:    133.9K
 * Total Submissions: 240.6K
 * Testcase Example:  '"ABCABC"\n"ABC"'
 *
 * For two strings s and t, we say "t divides s" if and only if s = t + ... + t
 * (i.e., t is concatenated with itself one or more times).
 * 
 * Given two strings str1 and str2, return the largest string x such that x
 * divides both str1 and str2.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: str1 = "ABCABC", str2 = "ABC"
 * Output: "ABC"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: str1 = "ABABAB", str2 = "ABAB"
 * Output: "AB"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: str1 = "LEET", str2 = "CODE"
 * Output: ""
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= str1.length, str2.length <= 1000
 * str1 and str2 consist of English uppercase letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    
    string gcdOfStrings(string str1, string str2) {
       if(str1+str2==str2+str1){
        return str1.substr(0,gcd(size(str1),size(str2)));
       }
       else{
        return "";
       }
    }
};
// @lc code=end

