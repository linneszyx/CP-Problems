/*
 * @lc app=leetcode id=784 lang=cpp
 *
 * [784] Letter Case Permutation
 *
 * https://leetcode.com/problems/letter-case-permutation/description/
 *
 * algorithms
 * Medium (73.61%)
 * Likes:    4080
 * Dislikes: 150
 * Total Accepted:    260.2K
 * Total Submissions: 353.1K
 * Testcase Example:  '"a1b2"'
 *
 * Given a string s, you can transform every letter individually to be
 * lowercase or uppercase to create another string.
 * 
 * Return a list of all possible strings we could create. Return the output in
 * any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "a1b2"
 * Output: ["a1b2","a1B2","A1b2","A1B2"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "3z4"
 * Output: ["3z4","3Z4"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 12
 * s consists of lowercase English letters, uppercase English letters, and
 * digits.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void backtracking(string s,int i ,int n,vector<string> &res){
        if(i==n) {
            res.push_back(s);
            return;
        }
        if(s[i]>='a' and s[i]<='z'){
            string temp = s.substr(0,i) + char(s[i]-32) + s.substr(i+1);
            backtracking(s,i+1,n,res);
            backtracking(temp,i+1,n,res);
        }
        else if(s[i]>='A' and s[i]<='Z'){
    string temp = s.substr(0,i) + char(s[i]+32) + s.substr(i+1);
            backtracking(s,i+1,n,res);
            backtracking(temp,i+1,n,res);
        }
        else{
            backtracking(s,i+1,n,res);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        backtracking(s,0,s.length(),res);
        return res;
    }
};
// @lc code=end

