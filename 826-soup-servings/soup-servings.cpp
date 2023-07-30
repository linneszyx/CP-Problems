class Solution {
public:
    double soupServings(int n) {
         if(n>4451) return 1.0;
         n=(n+24)/25;
         unordered_map<int,double> memo;
         return dp(n,n,memo);
    }
private:
    double dp(int a,int b,unordered_map<int,double>&memo){
        if(a<=0 and b<=0) return 0.5;
        if(a<=0){
            return 1.0;
        }
        if(b<=0) {
            return 0.0;
        }
        int key = a*500+b;
        if(memo.count(key)) return memo[key];
        memo[key] =0.25*(dp(a-4,b,memo)+dp(a-3,b-1,memo)+dp(a-2,b-2,memo)+dp(a-1,b-3,memo));
        return memo[key];
    }
};