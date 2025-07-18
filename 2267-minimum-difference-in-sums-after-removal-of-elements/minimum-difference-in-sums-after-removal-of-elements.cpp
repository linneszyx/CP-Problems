#define ll long long
class Solution {
public:
    ll minimumDifference(vector<int>& v) {
        priority_queue<int> l;
        priority_queue<int, vector<int>, greater<>> r;
        long n = v.size() / 3;
        long left = 0, right = 0, ans = LLONG_MAX;
        vector<long> temp(v.size());
        for (int i = v.size() - 1; i >= n; --i) {
            r.push(v[i]);
            right += v[i];
            if (r.size() > n) {
                right -= r.top();
                r.pop();
            }
            if (r.size() == n)
                temp[i] = right;
        }
        for (int i = 0; i < v.size() - n; i += 1) {
            l.push(v[i]);
            left += v[i];
            if (l.size() > n) {
                left -= l.top();
                l.pop();
            }
            if (l.size() == n)
                ans = min(ans, left - temp[i + 1]);
        }
        return ans;
    }
};