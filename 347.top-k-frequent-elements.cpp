/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int> m;
        priority_queue<pair<int,int>> q;
        for(auto num:nums) m[num]++;
        for(auto it:m) q.push({it.second,it.first});
        for(int i=0;i<k;i++){
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};
// @lc code=end

