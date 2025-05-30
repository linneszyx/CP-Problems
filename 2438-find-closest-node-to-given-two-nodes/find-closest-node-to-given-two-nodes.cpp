class Solution {
public:
    void dfs(int node,vector<int>&edges,vector<int>&dist,vector<bool>&vis){
        vis[node] = true;
        int ngh = edges[node];
        if(ngh!=-1 and vis[ngh]==false){
            dist[ngh] = dist[node]+1;
            dfs(ngh,edges,dist,vis);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        int ans = -1;
        int minDist = INT_MAX;
        vector<int> d1(n,0),d2(n,0);
        vector<bool> v1(n,false),v2(n,false);
        dfs(node1,edges,d1,v1);
        dfs(node2,edges,d2,v2);
        for(int currNode =0;currNode<n;currNode++){
            if(v1[currNode]==true and v2[currNode]==true and minDist>max(d1[currNode],d2[currNode])){
                minDist = max(d1[currNode],d2[currNode]);
                ans = currNode;
            }
        }
        return ans;
    }
};