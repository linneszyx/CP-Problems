
class Solution {
public:
int r(int n){
    int res=0;
    while(n!=0) {
        res=res*10+n%10;
        n/=10;
    }
    return res;
}
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int res=0;
        for(int i=0;i<nums.size();i+=1){
            int t = nums[i]-r(nums[i]);
            mp[t]++;
            res=(res+mp[t]-1)%1000000007;
        }
        return res%1000000007;
    }
};