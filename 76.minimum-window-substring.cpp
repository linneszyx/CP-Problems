/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int FP[256] = {0};
        int FS[256] = {0};
        for (int i = 0; i < t.length(); i++)
        {
            FP[t[i]]++;
        }
        int count = 0;        // count how many characters have been matched till now (string and pattern)
        int start = 0;        // start of the window (left pointer)
        int start_index = -1; // start index of the smallest window
        int min_window_size = INT_MAX;
        int window_size;
        // Sliding Window Algorithm
        for (int i = 0; i < s.length(); i++)
        {
            // expand the window by including the current character
            FS[s[i]]++;
            // if the current character is present in the pattern
            if (FS[s[i]] <= FP[s[i]])
            {
                count++;
            }
            // if all the characters have been matched
            if (count == t.length())
            {
                // start shrinking the window from the left
                while (FS[s[start]] > FP[s[start]] || FP[s[start]] == 0)
                {
                    if (FS[s[start]] > FP[s[start]])
                    {
                        FS[s[start]]--;
                    }
                    start++;
                }
                // window size
                window_size = i - start + 1;
                // return the smallest window
                if (min_window_size > window_size)
                {
                    min_window_size = window_size;
                    start_index = start;
                }
            }
        }
        if (start_index == -1)
        {
            return "";
        }
        return s.substr(start_index, min_window_size);
    }
};
// @lc code=end
