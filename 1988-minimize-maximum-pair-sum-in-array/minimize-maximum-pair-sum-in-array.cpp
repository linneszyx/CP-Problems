class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int mx = INT_MIN;
        int mnn = INT_MAX;
        int mxn = INT_MIN;
        vector<int> f(100001,0);
        for(int x : nums){
            f[x]++;
            mnn = min(mnn,x);
            mxn = max(mxn,x);
        }
        int l = mnn;
        int h = mxn;
        while(l<=h){
            if(f[l]==0) l+=1;
            else if(f[h]==0) h-=1;
            else {
                int cps = l+h;
                mx = max(mx,cps);
                f[l]--;
                f[h]--;
            }
        }
        return mx;
    }
};