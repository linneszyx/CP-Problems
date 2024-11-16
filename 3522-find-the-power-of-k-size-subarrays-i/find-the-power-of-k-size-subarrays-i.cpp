class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res;
        int l=0,cn=1;
        for(int r=0;r<nums.size();r+=1) {
            if(r>0 and nums[r-1]+1==nums[r]) cn++;
            if(r-l+1>k) {
                if(nums[l]+1==nums[l+1]) cn--;
                l++;
            }
            if(r-l+1==k) res.push_back(cn==k?nums[r]:-1);
        }
        return res;
    }
};