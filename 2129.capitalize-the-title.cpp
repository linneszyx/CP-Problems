/*
 * @lc app=leetcode id=2129 lang=cpp
 *
 * [2129] Capitalize the Title
 */

// @lc code=start
class Solution
{
public:
    string capitalizeTitle(string title)
    {
        int n = title.size();
        int i = 0;
        string ans;
        while (i < n)
        {
            int j = i;
            string temp;
            while (j < n && title[j] != ' ')
            {
                if (isupper(title[j]))
                {
                    temp += title[j] - 'A' + 'a';
                }
                else
                {
                    temp += title[j];
                }
                j++;
            }
            if (j - i > 2)
            {
                temp[0] = temp[0] - 'a' + 'A';
            }
            i = j + 1;
            ans += temp + " ";
        }
        ans.erase(ans.end() - 1);
        return ans;
    }
};
// @lc code=end
