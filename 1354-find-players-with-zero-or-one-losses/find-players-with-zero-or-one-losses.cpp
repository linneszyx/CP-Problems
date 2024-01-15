class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> wc,lc;
        int n = matches.size();
        for(auto i=0;i<n;i+=1){
            wc[matches[i][0]]++;
            lc[matches[i][1]]++;
        }
        vector<int> lO;
        auto it = lc.begin();
        while(it!=lc.end()){
            if(it->second==1) lO.push_back(it->first);
            it++;
        }
        vector<int> lZ;
        auto it2 = wc.begin();
        while(it2!=wc.end()){
            if(it2->second>=1 and lc[it2->first]==0) lZ.push_back(it2->first);
            it2++;
        }
        sort(lZ.begin(),lZ.end());
        sort(lO.begin(),lO.end());
        vector<vector<int>> ans;
        ans.push_back(lZ);
        ans.push_back(lO);
        return ans;
    }
};