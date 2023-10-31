//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
     void dfs(vector<int>adj[],int node,vector<int>&vis){
        
        vis[node]=1;
        
        for(auto it:adj[node]){
            if(!vis[it])dfs(adj,it,vis);
        }
        
        
    }
    
    
    bool isconnected(vector<int>adj[],vector<int>&mark,int s){
        
        
        vector<int>vis(26,0);
        
        dfs(adj,s,vis);
        
        for(int i=0;i<26;i++){
            if(mark[i] and !vis[i])return false;
        }
        
        return true;
        
    }
    
    public:
    
    int isCircle(int N, vector<string> A)
    {
        vector<int>adj[26];
        
        vector<int>indegree(26,0),outdegree(26,0);
        
        vector<int>mark(26,0);
        
        for(auto it:A){
            
            int f=it.front()-'a';
            
            int b=it.back()-'a';
            
            adj[f].push_back(b);
            
            indegree[b]++;
            
            outdegree[f]++;
            
            mark[f]=mark[b]=1;
            
        }
        
        for(int i=0;i<26;i++){
            if(indegree[i]!=outdegree[i])return false;
        }
        
        return isconnected(adj,mark,A[0].front()-'a');
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends