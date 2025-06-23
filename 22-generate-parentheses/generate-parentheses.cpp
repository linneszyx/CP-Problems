class Solution {
public:
    void ff(vector<string>& v, string str, int n, int m) {
        if (n == 0 and m == 0) {
            v.push_back(str);
            return;
        }
        if (m > 0)
            ff(v, str + ")", n, m - 1);
        if (n > 0)
            ff(v, str + "(", n - 1, m + 1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        ff(v, "", n, 0);
        return v;
    }
};