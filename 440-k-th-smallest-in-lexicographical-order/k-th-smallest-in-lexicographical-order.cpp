class Solution {
public:
int f(long a,long b,long &n){
    int g=0;
    while(a<=n) {
        g+=min(n+1,b)-a;
        a*=10;
        b*=10;
    }
    return g;
}
    int findKthNumber(long n, int k) {
        long num = 1;
        for(int i=1;i<k;) {
            int re = f(num,num+1,n);
            if(i+re<=k) {
                i+=re;
                num++;

            }
            else {
                i++;
                num*=10;
            }
        }
        return num;
    }
};