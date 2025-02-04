class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        const int n = nums.size();
        int mx=0,s=nums[0];
        for(int i=1;i<n;i+=1){
            if(nums[i]>nums[i-1]) s+=nums[i];
            else {
                mx=max(mx,s);
                s=nums[i];
            }
        }
        return max(mx,s);
    }
};