class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string r = "";
        int n = nums.size();
        for(int i = 0;i<n;i+=1) 
            r+=nums[i][i]=='0' ? '1' : '0';
            return r;
    }
};