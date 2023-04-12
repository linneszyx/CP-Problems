/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        string ans = "";
        vector<string> stk;
        int i = 0;
        while (i < path.size()) {
            while (i < path.size() && path[i] == '/') i++;
            if (i == path.size()) break;
            int j = i + 1;
            while (j < path.size() && path[j] != '/') j++;
            string sub = path.substr(i, j - i);
            if (sub == "..") {
                if (!stk.empty()) stk.pop_back();
            } else if (sub != ".") {
                stk.push_back(sub);
            }
            i = j;
        }
        for (auto &s : stk) {
            ans += "/" + s;
        }
        return ans.empty() ? "/" : ans;
    }
};
// @lc code=end

