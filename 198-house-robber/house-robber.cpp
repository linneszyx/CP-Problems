class Solution {
public:
    int rob(vector<int>& nums) {    
        int n = nums.size();
        int p2 = nums[0];
        if(n==1) return nums[0];
        int p1 = max(p2,nums[1]);
        for(int i=2;i<n;i++){
            int cur_house = max(p1,p2+nums[i]);
            p2 = p1;
            p1 = cur_house;
        }
        return p1;
    }
};