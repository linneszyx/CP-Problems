class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int xorr=nums[0];
        int maxxorr=pow(2,maximumBit)-1;
        for(int i=1;i<n;i+=1) {
            xorr^=nums[i];
        }
        vector<int> v(n);
        for(int i=0;i<n;i+=1){
            v[i]=xorr^maxxorr;
            xorr^=nums[n-1-i];
        }
        return v;
    }
};