/*
 * @lc app=leetcode id=2024 lang=cpp
 *
 * [2024] Maximize the Confusion of an Exam
 */

// @lc code=start
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int l = 0, r = 0;
        int maxLen = 0;
        int maxCnt = 0;
        int cnt = 0;
        while (r < n) {
            if (answerKey[r] == 'T') {
                cnt++;
            }
            while (cnt > k) {
                if (answerKey[l] == 'T') {
                    cnt--;
                }
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        l = 0, r = 0;
        cnt = 0;
        while (r < n) {
            if (answerKey[r] == 'F') {
                cnt++;
            }
            while (cnt > k) {
                if (answerKey[l] == 'F') {
                    cnt--;
                }
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};
// @lc code=end

