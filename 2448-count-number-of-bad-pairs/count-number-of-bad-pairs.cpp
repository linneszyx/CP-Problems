class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        long g=0;
        for(int i=0;i<nums.size();i+=1) {
            int k = nums[i]-i;
            g+=mp[k];
            mp[k]++;
        }
        long tp = static_cast<long>(nums.size())*(nums.size()-1)/2;
        return tp-g;
    }
};