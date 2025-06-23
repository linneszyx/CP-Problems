#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
class Solution {
public:
    int findMin(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int l=0,r=nums.size()-1;
        while(l<r){
            int m = l+(r-l)/2;
            if(nums[m]<nums[r]) r=m;
            else l=m+1;
        }
        return nums[l];
    }
};