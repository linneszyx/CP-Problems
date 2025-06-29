class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int c = 0;
        int mod = 1e9 + 7;
        sort(nums.begin(), nums.end());
        vector<int> v(n, 1);
        for (int i = 1; i < n; i += 1)
            v[i] = (v[i - 1] * 2) % mod;
        int l = 0, r = n - 1;
        while (l <= r) {
            if (nums[l] + nums[r] > target)
                --r;
            else {
                c = (c + v[r - l]) % mod;
                ++l;
            }
        }
        return c;
    }
};