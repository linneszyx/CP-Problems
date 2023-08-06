class Solution {
public:
   vector<vector<int>>result;
    void backper(vector<int> &nums,int s){
        int n = nums.size();
        if(s==n) result.push_back(nums);
        for(int i=s;i<n;i++){
            swap(nums[i],nums[s]);
            backper(nums,s+1);
            swap(nums[i],nums[s]);
        } 
    }
    vector<vector<int>> permute(vector<int>& nums) {
        backper(nums,0);
        return result;
    }
};