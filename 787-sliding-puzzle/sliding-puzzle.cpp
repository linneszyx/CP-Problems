class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> dir = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        string tar = "123450";
        set<string> vis;
        queue<string> q;
        string st = "";
        for(auto row : board) {
            for(auto col : row) {
                st+=col+'0';
            }
         }
         q.push(st);
         vis.insert(st);
         int step = 0;
         while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                string cur = q.front();
                q.pop();
                if(cur==tar) return step;
                int z = cur.find('0');
                for(auto move : dir[z]) {
                    string next = cur;
                    swap(next[move],next[z]);
                    if(!vis.count(next)) {
                        vis.insert(next);
                        q.push(next);
                    }
                }
            }
            step++;
         }
         return -1;
    }
};