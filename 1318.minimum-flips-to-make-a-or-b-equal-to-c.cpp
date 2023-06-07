/*
 * @lc app=leetcode id=1318 lang=cpp
 *
 * [1318] Minimum Flips to Make a OR b Equal to c
 */

// @lc code=start
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int bit_a = (a >> i) & 1;
            int bit_b = (b >> i) & 1;
            int bit_c = (c >> i) & 1;
            if (bit_c == 0) {
                res += bit_a + bit_b;
            } else {
                if (bit_a == 0 && bit_b == 0) {
                    ++res;
                }
            }
        }
        return res;
    }
};
// @lc code=end

