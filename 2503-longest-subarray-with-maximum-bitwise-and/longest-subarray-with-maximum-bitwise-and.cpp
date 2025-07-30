class Solution {
public:
    static int longestSubarray(vector<int>& nums) {
        const int n=nums.size();
        int m=max_element(nums.begin(), nums.end())-nums.begin(); 
        int maxLen=0, x = nums[m];

        for (int i = m; i < n; i++) {
            int len = 0;

            while (i < n && nums[i] == x) {
                i++;
                len++;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();