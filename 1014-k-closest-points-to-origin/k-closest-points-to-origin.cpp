#define vi vector<int>
#define vii vector<vi>

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vi> pq;
        vii ans(k);
        for (auto& p : points) {
            int x = p[0];
            int y = p[1];
            pq.push({x * x + y * y, x, y});
            if (pq.size() > k)
                pq.pop();
        }
        for (int i = 0; i < k; i += 1) {
            vi v = pq.top();
            pq.pop();
            ans[i] = {v[1], v[2]};
        }
        return ans;
    }
};