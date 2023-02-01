/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (43.52%)
 * Likes:    8015
 * Dislikes: 263
 * Total Accepted:    541.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1,
 * or false otherwise.
 * 
 * In other words, return true if one of s1's permutations is the substring of
 * s2.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "ab", s2 = "eidbaooo"
 * Output: true
 * Explanation: s2 contains one permutation of s1 ("ba").
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s1 = "ab", s2 = "eidboaoo"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s1.length, s2.length <= 10^4
 * s1 and s2 consist of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
   /**
    * It checks if two vectors are equal.
    * 
    * @param a the first string
    * @param b the string to be searched
    * 
    * @return a boolean value.
    */
    bool eql(vector<int> a,vector<int> b){
        for(int i=0;i<26;i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
    /**
     * We use a sliding window of size s1.size() and check if the frequency of characters in the window
     * is the same as the frequency of characters in s1
     * 
     * @param s1 the string we want to check if it's a permutation of a substring of s2
     * @param s2 the string to be checked
     * 
     * @return true if the string s2 contains the permutation of the string s1.
     */
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()){
            return false;
        }
       vector<int> freq_of_s1(26,0);
       for(char ch : s1) {
            freq_of_s1[c-'a']++;
       } 
       vector<int> freq_of_s2(26,0);
       int i=0,j=0;
       while(j<s2.size()){
        freq_of_s2[s2[j]-'a']++;
        if(j-i+1==s1.size()){
            if(eql(freq_of_s1,freq_of_s2)){
                return true;
            }
        }
        if(j-i+1<s1.size()) {
            j++;
        }
        else{
            freq_of_s2[s2[i]-'a']--;
            i++;
            j++;
        }
       }
       return false;
    }
};
// @lc code=end

