class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size(),res=1,in=1,de=1;
        for(int i=1;i<n;i+=1) {
            bool a = nums[i]>nums[i-1],b=nums[i]<nums[i-1];
            in=a*in+1;
            de=b*de+1;
            res = max(res,max(in,de));
        }
        return res;
    }
};