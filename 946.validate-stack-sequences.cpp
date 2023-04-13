/*
 * @lc app=leetcode id=946 lang=cpp
 *
 * [946] Validate Stack Sequences
 */

// @lc code=start
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
            int n = pushed.size();
            stack<int> s;
            int i = 0;
            for (int x : pushed) {
                s.push(x);
                while (!s.empty() && i < n && s.top() == popped[i]) {
                    s.pop();
                    i++;
                }
            }
            return i == n;
    }
};
// @lc code=end

