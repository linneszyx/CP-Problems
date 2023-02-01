/*
 * @lc app=leetcode id=845 lang=cpp
 *
 * [845] Longest Mountain in Array
 *
 * https://leetcode.com/problems/longest-mountain-in-array/description/
 *
 * algorithms
 * Medium (40.20%)
 * Likes:    2352
 * Dislikes: 65
 * Total Accepted:    106.4K
 * Total Submissions: 264.6K
 * Testcase Example:  '[2,1,4,7,3,2,5]'
 *
 * You may recall that an array arr is a mountain array if and only if:
 * 
 * 
 * arr.length >= 3
 * There exists some index i (0-indexed) with 0 < i < arr.length - 1 such
 * that:
 * 
 * arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
 * arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
 * 
 * 
 * 
 * 
 * Given an integer array arr, return the length of the longest subarray, which
 * is a mountain. Return 0 if there is no mountain subarray.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [2,1,4,7,3,2,5]
 * Output: 5
 * Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [2,2,2]
 * Output: 0
 * Explanation: There is no mountain.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 10^4
 * 0 <= arr[i] <= 10^4
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * Can you solve it using only one pass?
 * Can you solve it in O(1) space?
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int large = 0;
        for(int i=1;i<=n-2;){
            if(arr[i]>arr[i-1] and arr[i]>arr[i+1]){
                int c = 1;
                int j = i;
                while(j>=1 and arr[j]>arr[j-1]){
                    j--;
                    c++;
                }
                while(i<=n-2 and arr[i]>arr[i+1]){
                    i++;
                    c++;
                }
                large = max(large,c);
            }
            else{
                i++;
            }
        }
        return large;
    }
};
// @lc code=end

