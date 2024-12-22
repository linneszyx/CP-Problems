class Solution {
public:
    using int2 = pair<int,int>;
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size(),qz=queries.size();
        vector<int> ans(qz,-1);
        vector<int2> idx;
        for(int i=0;i<qz;i+=1) {
            int &x = queries[i][0],&y=queries[i][1];
            if(x>y) swap(x,y);
            if(x==y or heights[x]<heights[y]) ans[i]=y;
            else idx.emplace_back(y,i);
        }
        sort(idx.begin(),idx.end(),greater<>());
        vector<int2> st;
        int j=n-1;
        for(auto [_,i]:idx){
            int x = queries[i][0];
            int y = queries[i][1];
            for(;j>y;j--) {
                while(!st.empty() and heights[st.back().second]<heights[j]){ st.pop_back();}
                st.emplace_back(heights[j],j);
            }
            auto it = upper_bound(st.rbegin(),st.rend(),make_pair(heights[x],n));
            ans[i] = (it==st.rend()) ? -1 : it->second;
        }
        return ans;
    }
};