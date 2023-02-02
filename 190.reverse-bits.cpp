/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 *
 * https://leetcode.com/problems/reverse-bits/description/
 *
 * algorithms
 * Easy (52.99%)
 * Likes:    4085
 * Dislikes: 1055
 * Total Accepted:    590.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '00000010100101000001111010011100'
 *
 * Reverse bits of a given 32 bits unsigned integer.
 *
 * Note:
 *
 *
 * Note that in some languages, such as Java, there is no unsigned integer
 * type. In this case, both input and output will be given as a signed integer
 * type. They should not affect your implementation, as the integer's internal
 * binary representation is the same, whether it is signed or unsigned.
 * In Java, the compiler represents the signed integers using 2's complement
 * notation. Therefore, in Example 2 above, the input represents the signed
 * integer -3 and the output represents the signed integer -1073741825.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: n = 00000010100101000001111010011100
 * Output:    964176192 (00111001011110000010100101000000)
 * Explanation: The input binary string 00000010100101000001111010011100
 * represents the unsigned integer 43261596, so return 964176192 which its
 * binary representation is 00111001011110000010100101000000.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 11111111111111111111111111111101
 * Output:   3221225471 (10111111111111111111111111111111)
 * Explanation: The input binary string 11111111111111111111111111111101
 * represents the unsigned integer 4294967293, so return 3221225471 which its
 * binary representation is 10111111111111111111111111111111.
 *
 *
 *
 * Constraints:
 *
 *
 * The input must be a binary string of length 32
 *
 *
 *
 * Follow up: If this function is called many times, how would you optimize it?
 *
 */

// @lc code=start
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        int vic[32] = {0};
        int i = 0;
       /* Converting the binary number to decimal number. */
        while (n != 0)
        {
            int r = 0;
            r = n % 2;
            vic[i] = r;
            n /= 2;
            i++;
        }
        long long res = 0;
        for (int i = 0; i < 32; i++)
        {
            res += vic[i] * pow(2, 32 - 1 - i);
        }
        return res;
    }
};
// @lc code=end
