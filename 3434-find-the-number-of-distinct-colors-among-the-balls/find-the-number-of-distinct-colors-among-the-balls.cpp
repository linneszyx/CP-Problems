class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> ball,color;
        vector<int> res;
        res.reserve(queries.size());
        int dist = 0;
        for(auto &q : queries) {
            int p = q[0],c=q[1];
            if(ball.count(p)) 
                if(--color[ball[p]]==0) {
                    color.erase(ball[p]);
                    dist--;
                }
                ball[p]=c;
                if(++color[c]==1) dist++;
                res.push_back(dist);
        }
        return res;
    }
};