class Solution {
public:
    int maxSum(vector<int>& nums) {
        bool f = true;
        int maxval = INT_MIN;
        for (auto x : nums) {
            if (x >= 0)
                f = false;
            if (x > maxval)
                maxval = x;
        }
        if (f)
            return maxval;
        unordered_set<int> mp(nums.begin(), nums.end());
        int s = 0;
        for (auto x : mp)
            if (x > 0)
                s += x;
        return s;
    }
};