class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        for(int i=0;i<n;i+=1) {
            for(int j=i+1;j<n;j+=1){
                if(nums[i]+nums[j]==target) return new int[]{i,j};
            }
        }
        return new int[]{};
    }
}