//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    vector<int> tin,vis,low,mark;
    int timer = 0;

    void findArticularPoint(int node,int parent,vector<int> adj[]){
        tin[node]=low[node]=timer;
        timer++;
        vis[node] =1;
        
        int child=0;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                findArticularPoint(it,node,adj);
                low[node]=min(low[node],low[it]);
                
                if(low[it]>=tin[node] && parent != -1) 
                    mark[node]=1;
                
                child++;
            }
            else{
                low[node]=min(tin[it],low[node]);
            }
        }
        if(child>1 && parent==-1) mark[node]=1;
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        tin.resize(V);
        vis.resize(V,0);
        low.resize(V);
        mark.resize(V,0);
        
        findArticularPoint(0,-1,adj);
        vector<int> ans;
        for(int i=0; i<V; i++)
            if(mark[i]==1) ans.push_back(i);
            
        if(ans.size()==0) return {-1} ;
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
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends