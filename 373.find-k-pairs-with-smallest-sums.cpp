/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
            
            vector<vector<int>> res;
            if (nums1.empty() || nums2.empty() || k <= 0) return res;
    
            auto cmp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
                return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
            };
    
            priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    
            for (int i = 0; i < nums1.size() && i < k; ++i) {
                pq.push({i, 0});
            }
    
            while (k-- > 0 && !pq.empty()) {
                auto cur = pq.top(); pq.pop();
                res.push_back({nums1[cur.first], nums2[cur.second]});
                if (cur.second + 1 < nums2.size()) {
                    pq.push({cur.first, cur.second + 1});
                }
            }
    
            return res;
    }
};
// @lc code=end

