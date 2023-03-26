/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> op;
        for (auto num : nums)
        {
            op.push_back(to_string(num));
        }
        sort(op.begin(), op.end(), [](string &s1,string &s2){
            return s1+s2 > s2+s1;
        });
        string ans;
        for (auto x : op)
        {
            ans += x;
        }
        while(ans[0]=='0' and ans.length()>1) {
            ans.erase(0,1);
        }
        return ans;
    }
};
// @lc code=end
