/*
 * @lc app=leetcode id=2551 lang=cpp
 *
 * [2551] Put Marbles in Bags
 */

// @lc code=start
class Solution {
public:

    long long putMarbles(vector<int>& weights, int k) { 
        long long minans = weights[0] + weights[weights.size()-1];
        long long maxans = minans;
        priority_queue<int> pqmax;
        priority_queue<int, vector<int>, greater<int>> pqmin;
        for(int i=1;i<weights.size();i++){
            pqmin.push(weights[i]+weights[i-1]);
            pqmax.push(weights[i]+weights[i-1]);
        }
        for(int i=1;i<k;i++){
            minans+=pqmin.top();
            maxans+=pqmax.top();
            pqmin.pop();
            pqmax.pop();
        }
        return maxans-minans;
    }
};
// @lc code=end

