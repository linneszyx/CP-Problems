class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> mp;
        for(const auto &row : matrix) {
            string pattern;
            if(row[0]==0) {
                for(int bit : row) pattern+=to_string(bit);
            }
            else {
                for(int bit : row) pattern+=to_string(bit^1);
            }
            mp[pattern]++;
        }
        int mf = 0;
        for(const auto  &pair : mp) {
            mf=max(mf,pair.second);
        }
        return mf;
    }
};