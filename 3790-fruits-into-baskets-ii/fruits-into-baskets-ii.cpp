class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int r = fruits.size();
        for(auto x : fruits) {
            for(auto &y : baskets) {
                if(x<=y) {
                    r--;
                    y=0;
                    break;
                }
            }
        }
        return r;
    }
};