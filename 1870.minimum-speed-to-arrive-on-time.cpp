/*
 * @lc app=leetcode id=1870 lang=cpp
 *
 * [1870] Minimum Speed to Arrive on Time
 */

// @lc code=start
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if(hour<=n-1) return -1;
        int l=1, r=1e7;
        while(l<r){
            int m = l+(r-l)/2;
            double t=0;
            for(int i=0;i<n-1;i++){
                t+=ceil((double)dist[i]/m);
            }
            t+=(double)dist[n-1]/m;
            if(t>hour) l=m+1;
            else r=m;
        }
        return l;
    }
};
// @lc code=end

