const int mod = 1e9+7;
int mod_add(int a,int b){
    a%=mod;
    b%=mod;
    return (((a+b)%mod)+mod)%mod;
}
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int nums[26] = {0};
        for(char ch : s) nums[ch-'a']++;
        while(t--){
            int curr[26] = {0};
            for(int j=0;j<26;j+=1){
                if(j==25 and nums[j]>0){
                    curr[0] = mod_add(curr[0],nums[j]);
                    curr[1] = mod_add(curr[1],nums[j]);
                }
                else {
                    if(j<25) 
                    {
                        curr[j+1] = mod_add(curr[j+1],nums[j]);
                    }
                }
            }
            for(int j=0;j<26;j+=1) {
                nums[j] = curr[j];
            }
        }
        int ans = 0;
        for(int i : nums) ans = mod_add(ans,i);
        return (int)ans;
    }
};