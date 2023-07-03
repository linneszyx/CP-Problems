/*
 * @lc app=leetcode id=859 lang=cpp
 *
 * [859] Buddy Strings
 */

// @lc code=start
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        bool res = false;
        if (s.size() != goal.size()) return res;
        if (s == goal) {
            unordered_set<char> st;
            for (char c : s) {
                if (st.count(c)) {
                    res = true;
                    break;
                }
                st.insert(c);
            }
            return res;
        }
        vector<int> diff;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != goal[i]) diff.push_back(i);
        }
        if (diff.size() == 2 && s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]]) res = true;
        return res;
        
    }
};
// @lc code=end

