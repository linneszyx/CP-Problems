class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cs = 0;
        int maxi = INT_MIN;
        for(auto x : nums) {
            cs = max(x,cs+x);
            maxi = max(maxi,cs);
        }
        return maxi;
    }
};