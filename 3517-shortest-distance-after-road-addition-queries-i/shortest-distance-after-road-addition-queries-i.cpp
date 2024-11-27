#define vvi vector<vector<int>>
#define vi vector<int>
class Solution {
public:
    void create(vvi &adj,int n) {
        for(int i=0;i<n-1;i+=1) adj[i].push_back(i+1);
    }
    void dfs(int src,vi &topo,vi &vis,const vvi &adj){
        vis[src]=1;
        for(int node : adj[src]) {
            if(!vis[node]) dfs(node,topo,vis,adj);
        }
        topo.push_back(src);
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vvi adj(n);
        create(adj,n);
        vi ans;
        for(auto &edge : queries) {
            int u=edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            vi topo,vis(n,0);
            for(int i=0;i<n;i++) {
                if(!vis[i]) dfs(i,topo,vis,adj);
            }
            reverse(topo.begin(),topo.end());
            vi dist(n,1e9);
            dist[0]=0;
            for(int node : topo) {
                if(dist[node]!=1e9) {
                    for(int nbr : adj[node]) {
                        if(dist[nbr]>dist[node]+1) {
                            dist[nbr]=dist[node]+1;
                        }
                    }
                }
            }
            ans.push_back(dist[n-1]);      
        }
        return ans;
    }
};