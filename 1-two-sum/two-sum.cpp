class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int,int> mp;
      for(int i=0;i<nums.size();i+=1) {
        int n=nums[i];
        if(mp.find(target-n)!=mp.end()) {
            return {i,mp[target-n]};
        }
        mp[n]=i;
      }
      return {};
    }
};