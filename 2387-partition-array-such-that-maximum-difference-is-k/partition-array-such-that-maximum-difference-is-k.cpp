class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int res = 1;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mini = nums[0];
        for(int i=1;i<n;i+=1) {
            if(nums[i]-mini > k) {
                res++;
                mini = nums[i];
            }
        }
        return res;
    }
};