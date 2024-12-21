#define ll long long
#define vi vector<int>
#define vii vector<vi>
#define vll vector<ll>
class Solution {
public:
int k,res;
vi values;
vll s;
vii adj;
void dfs(int u,int p) {
    s[u]=values[u];
    for(int v : adj[u]) {
        if(v==p) continue;
        dfs(v,u);
        s[u]+=s[v];
    }
    if(s[u]%k==0) {
        res++;
        s[u]=0;
    }
}
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        adj.resize(n);
        s.resize(n);
        for(auto &e:edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        this->values=values;
        this->k=k;
        res=0;
        dfs(0,-1);
        return res;
    }
};