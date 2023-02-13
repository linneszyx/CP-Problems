/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (48.78%)
 * Likes:    14892
 * Dislikes: 613
 * Total Accepted:    1M
 * Total Submissions: 2.1M
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers nums, return the length of the longest
 * consecutive elements sequence.
 *
 * You must write an algorithm that runs in O(n) time.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [100,4,200,1,3,2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,3,7,2,5,8,4,6,0,1]
 * Output: 9
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        int largestLen = 0;
        unordered_set<int> s;
        for (int x : nums)
        {
            s.insert(x);
        }
        for (auto ele : s)
        {
            int pare = ele - 1;
            if (s.find(pare) == s.end())
            {
                int next = ele + 1;
                int count = 1;
                while (s.find(next) != s.end())
                {
                    count++;
                    next++;
                }
                if (count >=largestLen)
                {
                    largestLen = count;
                }
            }
        }
        return largestLen;
    }
};
// @lc code=end
