/*
 * @lc app=leetcode id=2316 lang=cpp
 *
 * [2316] Count Unreachable Pairs of Nodes in an Undirected Graph
 */

// @lc code=start
class Solution {
public:
   void dfs(vector<int> vec[], int node, vector<bool> &vis, int &counter){
        vis[node] = true;
        counter++;
        for(auto ele : vec[node]){
            if(!vis[ele]){
                dfs(vec,ele,vis,counter);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
       vector<int> vec[n];
       for(auto ele : edges){
              vec[ele[0]].push_back(ele[1]);
              vec[ele[1]].push_back(ele[0]);
       }
         long long ans = 0;
         vector<bool> vis(n,false);
         vector<int> temp;
            for(int i = 0; i < n; i++){
                if(!vis[i]){
                    int counter = 0;
                    dfs(vec,i,vis,counter);
                    temp.push_back(counter);
                   
                }
            }
            int total = 0;
            for(int i=0;i<temp.size();i++){
               ans+=(long)((long)temp[i]*(long)(n-total-temp[i]));
                total += temp[i];
            }
            return ans;
    }
};
// @lc code=end

