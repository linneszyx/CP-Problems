class Solution {
public:
    int passThePillow(int n, int time) {
        int cp  = time/(n-1);
        int rr = time%(n-1);
        int ans = 0;
        if(cp%2!=0) ans = n-rr;
        else ans = rr+1;
        return ans;
    }
};