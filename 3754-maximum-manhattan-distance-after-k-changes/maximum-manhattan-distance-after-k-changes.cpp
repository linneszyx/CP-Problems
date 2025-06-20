class Solution {
public:
    int maxDistance(string s, int k) {
        int res = 0;
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i+=1) {
            mp[s[i]]++;
            int d = abs(mp['N']-mp['S'])+abs(mp['E']-mp['W']);
            res = max(res,d+min(2*k,i+1-d));
        }
        return res;
    }
};