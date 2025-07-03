class Solution {
public:
    char kthCharacter(int k) {
        if(k==1) return 'a';
        int c=0;
        for(auto b = bit_ceil((unsigned)k);b>1;b>>=1) {
            if(k>b/2) {
                k-=b/2;
                c++;
            }
        }
        return 'a'+(c%26);
    }
};