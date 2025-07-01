class Solution {
public:
    int possibleStringCount(string word) {
          int n = word.size(), res = n;
        for (int i = 1; i < n; ++i)
            res -= word[i] != word[i - 1];
        return res;
    }
};