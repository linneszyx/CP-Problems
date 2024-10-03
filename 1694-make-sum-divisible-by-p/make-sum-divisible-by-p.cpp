class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long ts=0;
        for(int x : nums) ts+=x;
        int r = ts%p;
        if(r==0) return 0;
        unordered_map<int,int> pm;
        pm[0]=-1;
        long ps=0;
        int minLen = nums.size();
        for(int i=0;i<nums.size();i+=1){
            ps+=nums[i];
            int cm=ps%p;
            int tm =(cm-r+p)%p;
            if(pm.find(tm)!=pm.end()){
                minLen=min(minLen,i-pm[tm]);
            }
            pm[cm]=i;
        }
        return minLen==nums.size()?-1:minLen;
    }
};