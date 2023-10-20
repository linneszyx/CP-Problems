//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
   bool dfs(vector<int> adj[],vector<int> &vis,int start,int parent[]){
        vis[start] = 1;
        bool ans = false;
        for(auto itr : adj[start]){
            if(vis[itr] == 0){
                parent[start] = 1;
                ans = ans || dfs(adj,vis,itr,parent);
                parent[start] = 0;
            }
            else{
                if(parent[itr] == 1 or itr == start)return true;
            }
        }
        return ans;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        int parent[V] = {0};
        for(int i = 0;i < V;i++){
            if(vis[i] == 0){
                if(dfs(adj,vis,i,parent))return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends