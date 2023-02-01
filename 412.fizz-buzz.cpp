/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 *
 * https://leetcode.com/problems/fizz-buzz/description/
 *
 * algorithms
 * Easy (69.32%)
 * Likes:    1451
 * Dislikes: 208
 * Total Accepted:    859.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '3'
 *
 * Given an integer n, return a string array answer (1-indexed) where:
 * 
 * 
 * answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
 * answer[i] == "Fizz" if i is divisible by 3.
 * answer[i] == "Buzz" if i is divisible by 5.
 * answer[i] == i (as a string) if none of the above conditions are true.
 * 
 * 
 * 
 * Example 1:
 * Input: n = 3
 * Output: ["1","2","Fizz"]
 * Example 2:
 * Input: n = 5
 * Output: ["1","2","Fizz","4","Buzz"]
 * Example 3:
 * Input: n = 15
 * Output:
 * ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> fizzBuzz(int n) {
     vector<string> ans;
     for (int i = 1; i <= n; i++)
     {
        if(i%3==0 and i%5==0){
            ans.push_back("FizzBuzz");
        }
        else if(i%3==0){
            ans.push_back("Fizz");
        }
        else if(i%5==0){
            ans.push_back("Buzz");
        }
        else {
            ans.push_back(to_string(i));
        }
     }
      return ans;  
    }
};
// @lc code=end

