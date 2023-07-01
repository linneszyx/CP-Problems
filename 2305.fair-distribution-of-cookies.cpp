/*
 * @lc app=leetcode id=2305 lang=cpp
 *
 * [2305] Fair Distribution of Cookies
 */

// @lc code=i
class Solution {
public:
    void helper(int i, vector<int>& cookies, vector<int>& temp, int k, int& ans) {
        int n = cookies.size();
        if(i==n){
            int maxi = INT_MIN;
            for(int i=0;i<k;i++){
                maxi=max(maxi,temp[i]);
            }
            ans = min(ans,maxi);
            return;
        }
        for(int j=0;j<k;j++){
            temp[j]+=cookies[i];
            helper(i+1,cookies,temp,k,ans);
            temp[j]-=cookies[i];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int ans = INT_MAX;
        vector<int> temp(k,0);
        helper(0,cookies, temp, k, ans);
        return ans;
    }
};
// @lc code=end

