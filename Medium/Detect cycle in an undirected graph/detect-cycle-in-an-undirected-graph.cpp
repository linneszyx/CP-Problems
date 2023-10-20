//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
   bool bfs(int node,vector<int> adj[],unordered_map<int,bool>&visited){
        unordered_map<int,int> parent;
        parent[node]=-1;
        visited[node]=1;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto i:adj[front]){
                if(!visited[i]){
                    visited[i]=1;
                    q.push(i);
                    parent[i]=front;
                }else if(i!=parent[front]){
                    return 1;
                }
            }
        }
        return 0;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int,bool>visited;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool ans=bfs(i,adj,visited);
                if(ans){
                    return 1;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends