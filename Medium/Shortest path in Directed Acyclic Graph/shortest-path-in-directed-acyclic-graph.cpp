//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        for(int i=0;i<M;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        vector<int> dist(N,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        dist[0] = 0;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int node  = curr.second;
            int w = curr.first;
            for(auto it : adj[node]){
                int wt = it.second;
                int adjn = it.first;
                if(w+wt<dist[adjn]){
                    dist[adjn] = w+wt;
                    pq.push({dist[adjn],adjn});
                }
            }
        } 
        for(int i=0;i<dist.size();i++){
        if(dist[i]==INT_MAX) dist[i]=-1;
    }
    return dist;
    }   
   
    
    
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends