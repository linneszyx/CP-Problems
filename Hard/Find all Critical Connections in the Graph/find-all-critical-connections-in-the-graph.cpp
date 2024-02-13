//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
   void dfs(vector<vector<int>>& ans, vector<int> adj[], vector<bool>& vis, vector<int>& low, vector<int>& disc, int src, int parent, int& timer) {
        vis[src] = true;
        low[src] = disc[src] = timer++;
        for (int nbr : adj[src]) {
            if (nbr == parent)
                continue;
            
            if (!vis[nbr]) {
                dfs(ans, adj, vis, low, disc, nbr, src, timer);
                // Check if low is updated or not
                if (disc[src] < low[nbr]) {
                    ans.push_back({src, nbr});
                } else {
                    low[src] = min(low[src], low[nbr]);
                }
            } else {
                low[src] = min(low[src], disc[nbr]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int v, vector<int> adj[]) {
        vector<bool> vis(v, false);
        vector<int> low(v, 0), disc(v, 0);
        int parent = -1;
        int timer = 0;
        vector<vector<int>> ans;
        
        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                dfs(ans, adj, vis, low, disc, i, parent, timer);
            }
        }
        
        for (auto& bridge : ans)
            sort(bridge.begin(), bridge.end());
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends