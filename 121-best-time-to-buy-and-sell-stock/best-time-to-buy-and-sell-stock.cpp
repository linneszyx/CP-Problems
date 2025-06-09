class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p = 0;
        int mc = prices[0];
        int n = prices.size();
        for(int i=0;i<n;i++) {
           mc = min(mc,prices[i]);
           p = max(p,prices[i]-mc);
        }
        return p;
    }
};