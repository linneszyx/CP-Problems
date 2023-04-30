/*
 * @lc app=leetcode id=1579 lang=cpp
 *
 * [1579] Remove Max Number of Edges to Keep Graph Fully Traversable
 */

// @lc code=start
class Solution {
public:
    int find(int x, vector<int>& parent){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x],parent);
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int size = edges.size();
        vector<int> parent(n+1);
        for(int i=0;i<=n;i++) parent[i] = i;
        int ans = 0;
        for(int i=0;i<size;i++){
            if(edges[i][0] == 3){
                int x = find(edges[i][1],parent);
                int y = find(edges[i][2],parent);
                if(x == y) ans++;
                else parent[x] = y;
            }
        }
        vector<int> parent1 = parent;
        for(int i=0;i<size;i++){
            if(edges[i][0] == 1){
                int x = find(edges[i][1],parent);
                int y = find(edges[i][2],parent);
                if(x == y) ans++;
                else parent[x] = y;
            }
        }
        for(int i=0;i<size;i++){
            if(edges[i][0] == 2){
                int x = find(edges[i][1],parent1);
                int y = find(edges[i][2],parent1);
                if(x == y) ans++;
                else parent1[x] = y;
            }
        }
        int count = 0;
        for(int i=1;i<=n;i++){
            if(parent[i] == i) count++;
        }
        int count1 = 0;
        for(int i=1;i<=n;i++){
            if(parent1[i] == i) count1++;
        }
        if(count > 1 || count1 > 1) return -1;
        return ans;
    }
};
// @lc code=end

