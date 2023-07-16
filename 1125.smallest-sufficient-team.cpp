/*
 * @lc app=leetcode id=1125 lang=cpp
 *
 * [1125] Smallest Sufficient Team
 */

// @lc code=start
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
          int n = req.size();
          map<string, int> m;
          for(int i=0;i<req.size();i++) m[req[i]] = i;
          vector<vector<int>> v;
          for(int i=0;i<people.size();i++){
            vector<int> t;
            for(int j=0;j<people[i].size();j++){
                t.push_back(m[people[i][j]]);
            }
            v.push_back(t);
          }     
          unordered_map<int, vector<int>> dp;
          dp.reserve(1<<n);
            dp[0] = {};
            for(int i=0;i<v.size();i++){
                for(auto it=dp.begin();it!=dp.end();it++){
                    int k = it->first;
                    vector<int> t = it->second;
                    int nk = k;
                    for(int j=0;j<v[i].size();j++){
                        nk |= (1<<v[i][j]);
                    }
                    if(dp.find(nk)==dp.end() || dp[nk].size()>t.size()+1){
                        t.push_back(i);
                        dp[nk] = t;
                    }
                }

            }
            return dp[(1<<n)-1];
    }
};
// @lc code=end

