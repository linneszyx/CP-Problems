class Solution {
public:
    int minMaxDifference(int num) {
      int min_v = num,max_v = num;
      for(int i=0;i<10;i+=1) {
        int l=0,h=0,mul = 1;
        for(int n=num;n;n/=10) {
            bool f = n%10==i;
            l+=(f?0:n%10)*mul;
            h+=(f?9:n%10)*mul;
            mul*=10;
        }
        min_v = min(min_v,l);
        max_v = max(max_v,h);
      }
      return max_v-min_v;
    }
};