class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        for(int i=0;i<prices.size();i+=1) {
            int x=i+1;
            while(x<prices.size() and prices[x]>prices[i]) x++;
            if(x<prices.size()) prices[i]-=prices[x];
        }
    return prices;
    }
};