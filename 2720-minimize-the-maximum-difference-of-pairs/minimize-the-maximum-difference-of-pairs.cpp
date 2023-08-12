class Solution {
public:
    bool solve(vector<int>&nums,int m,int p){
        int c=0;
        for(int i=0;i<nums.size()-1 and c<p;){
            if(nums[i+1]-nums[i]<=m) {
                c++;
                i+=2;
            }
            else{
                i++;
            }
        }
        return c>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int left=0,right=nums.back()-nums.front();
        while(left<right){
            int m=(left+right)/2;
            if(solve(nums,m,p)) right=m;
            else left=m+1;
        }
    return left;
    }
};