/*
 * @lc app=leetcode id=2462 lang=cpp
 *
 * [2462] Total Cost to Hire K Workers
 */

// @lc code=start
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
       int l = candidates, r = costs.size() - candidates - 1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        if(l>r){
            sort(costs.begin(),costs.end());
            long long sum = 0;
            for(int i=0;i<k;i++){
                sum+=costs[i];
            }
            return sum;
        }
        long long sum = 0;
        for(int i=0;i<l;i++) pq.push({costs[i],i});
        for(int i=costs.size()-1;i>r;i--) pq.push({costs[i],i});
        while(l<=r && k>0){
            auto x = pq.top();
            pq.pop();
            if(x.second<l){
                pq.push({costs[l],l});
                l++;
            }
            else{
                pq.push({costs[r],r});
                r--;
            }
            sum+=x.first;
            k--;
        }
        while(k>0){
            auto x = pq.top();
            pq.pop();
            sum+=x.first;
            k--;
        }
        return sum;

       
    }
};
// @lc code=end

