class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&mp,unordered_map<int,bool>&vis,int sv,vector<int>&ans){
        for(auto x: mp[sv]){
            if(!vis[x]){
                vis[x] = true;
                ans.push_back(x);
                dfs(mp,vis,x,ans);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> ans;
        unordered_map<int,bool> vis;
        unordered_map<int,vector<int>> mp;
        for(auto x : adjacentPairs) {
            mp[x[0]].push_back(x[1]);
            mp[x[1]].push_back(x[0]);
        }
        int s;
        for(auto x:mp){
            if(x.second.size()==1) {
                s=x.first;
                break;
            }
        }
        vis[s] = true;
        ans.push_back(s);
        dfs(mp,vis,s,ans);
        return ans;
    }
};