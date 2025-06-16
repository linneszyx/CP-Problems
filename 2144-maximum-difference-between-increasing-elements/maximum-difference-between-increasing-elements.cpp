class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int xm = nums[0];
        int n = nums.size();
        int maxi = -1;
        for(int i=1;i<n;i+=1) {
            int x = nums[i];
            if(x<=xm) xm = x;
            else maxi = max(maxi,x-xm);
        }
        return maxi;
    }
};