class Solution {
public:
    int minBitFlips(int x, int y) {
        int xx=x^y;
        int zz=x&y&xx;
        bitset<32> xb(xx), zb(zz);
        return xb.count()+zb.count();
    }
};