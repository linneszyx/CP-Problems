class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int tc=0;
        vector<unordered_map<int,int>> dp(n);
        for(int i=1;i<n;i+=1){
            for(int j=0;j<i;j+=1){
                long long diff = static_cast<long long>(nums[i])-nums[j];
                if(diff>INT_MAX || diff<INT_MIN) continue;
                int diff_int = static_cast<int>(diff);
                dp[i][diff_int] +=1;
                if(dp[j].count(diff_int)){
                    dp[i][diff_int]+=dp[j][diff_int];
                    tc+=dp[j][diff_int];
                }
            }
        }
        return tc;
    }
};