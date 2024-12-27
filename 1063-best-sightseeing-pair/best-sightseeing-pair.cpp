class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int x = INT_MIN;
        int xx=  values[0];
        for(int i=1;i<values.size();i+=1){
            if(values[i]-i+xx>x) x=values[i]-i+xx;
            if(values[i]+i>xx) xx=values[i]+i;
        }
        return x;
    }
};