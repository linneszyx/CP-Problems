class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        stack<int> st;
        vector<int> v(n, 0);
        for (int i = n - 1; i >= 0; i -= 1) {
            while (!st.empty() and t[st.top()] <= t[i])
                st.pop();
            if (!st.empty())
                v[i] = st.top() - i;
            st.push(i);
        }
        return v;
    }
};