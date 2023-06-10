/*
 * @lc app=leetcode id=1802 lang=cpp
 *
 * [1802] Maximum Value at a Given Index in a Bounded Array
 */

// @lc code=start
class Solution {
public:
    long calc(long val){
        return (val*(val+1))/2;
    }
    long getSum(int totalLen,int val){
        long totalSum = 0;
        int delta = val;
        if(totalLen>=delta){
            long curSum = calc(val);
            int rm = totalLen - delta;
            totalSum = curSum+rm;
        }
        else {
            long lastval = delta - totalLen;
            totalSum = calc(val) - calc(lastval);
        }
        return totalSum;
    }
    int maxValue(int n, int index, int maxSum) {
        int low = 1,high = maxSum;
        int leftCount = index , rightCount = n - index - 1;
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            long leftSum = getSum(leftCount,mid-1);
            long rightSum = getSum(rightCount,mid-1);
            long totalSum = leftSum + rightSum + mid;
            if(totalSum > maxSum){
                high = mid - 1;
            }
            else {
                ans = mid;
                low = mid + 1;
            }
        }
        return ans;
    }
};
// @lc code=end

