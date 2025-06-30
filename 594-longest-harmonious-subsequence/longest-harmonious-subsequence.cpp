class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto x : nums)
            mp[x]++;
        int res = 0;
        for (auto x : mp) {
            if (mp.count(x.first - 1) > 0) {
                res = max(res, x.second + mp[x.first - 1]);
            }
        }
        return res;
    }
};