class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int i=0;
       int x = nums.size();
       for(int j=0;j<x;j++){
        if(nums[i]!=nums[j]) {
            i++;
        }
        nums[i]=nums[j];
       }
       return i+1;
    }
};