/*
 * @lc app=leetcode id=1675 lang=cpp
 *
 * [1675] Minimize Deviation in Array
 */

// @lc code=start
class Solution {
public:
   /**
    * The above function is creating a set of pairs of long longs.
    * 
    * @param nums The array of integers.
    * 
    * @return The minimum difference between the maximum and minimum values of the set.
    */
    int minimumDeviation(vector<int>& nums) {
     set<pair<long long, long long>> s;
        for (int num : nums) {
            if (num % 2 == 1) {
                s.insert({num * 2, num * 2});
            } else {
                s.insert({num, num});
            }
        }
        long long ans = s.rbegin()->first - s.begin()->first;
        while (s.rbegin()->first % 2 == 0) {
            auto it = s.end();
            --it;
            long long x = it->first, y = it->second;
            s.erase(it);
            s.insert({x / 2, y});
            ans = min(ans, s.rbegin()->first - s.begin()->first);
        }
        return ans;   
    }
};
// @lc code=end

