/*
 * @lc app=leetcode id=839 lang=cpp
 *
 * [839] Similar String Groups
 */

// @lc code=start
class Solution {
public:

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<int> parent(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };
        auto isSimilar = [&](const string& a, const string& b) {
            int cnt = 0;
            for (int i = 0; i < a.size(); ++i) {
                if (a[i] != b[i]) ++cnt;
                if (cnt > 2) return false;
            }
            return true;
        };
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n ; ++j) {
                if (isSimilar(strs[i], strs[j])) {
                    int pi = find(i), pj = find(j);
                    if (pi != pj) parent[pi] = pj;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (parent[i] == i) ++ans;
        }
        return ans;
    }
};
// @lc code=end

