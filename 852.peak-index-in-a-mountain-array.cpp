/*
 * @lc app=leetcode id=852 lang=cpp
 *
 * [852] Peak Index in a Mountain Array
 */

// @lc code=start
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (arr[mid] < arr[mid + 1]) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};
// @lc code=end

