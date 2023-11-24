class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size();
        sort(piles.begin(),piles.end());
        int s = n-2;
        int e = n/3;
        int ans = 0;
        
       while(s>=e) {ans+=piles[s];s=s-2;}
        return ans;
    }
};