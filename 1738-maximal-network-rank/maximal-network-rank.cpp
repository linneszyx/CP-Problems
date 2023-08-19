class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> d(n,0);
        set<pair<int,int>> rs;
        for(auto &r : roads){
            d[r[0]]++;
            d[r[1]]++;
            rs.insert({r[0],r[1]});
            rs.insert({r[1],r[0]});
        }
        int mr = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;++j){
                int x = d[i]+d[j];
                if(rs.find({i,j})!=rs.end()) x--;
            mr = max(mr,x);
            }
        }
        return mr;
    }
};