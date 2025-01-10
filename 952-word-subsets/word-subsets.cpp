class Solution {
public:
    vector<string> wordSubsets(vector<string>& w1, vector<string>& w2) {
        int mx[26]= {0};
        int t[26];
        for(const auto& w : w2) {
            memset(t,0,sizeof(t));
            for(char ch : w) t[ch-'a']++;
            for(int i=0;i<26;i+=1) mx[i]=max(mx[i],t[i]);
        }
        vector<string> uw;
        for(const auto & w : w1) {
            memset(t,0,sizeof(t));
            for(char ch : w) t[ch-'a']++;
            bool ff = true;
            for(int i=0;i<26;i+=1) {
                if(mx[i]>t[i]) {
                    ff=false;
                    break;
                }
            }
            if(ff) uw.emplace_back(w);
        }
        return uw;
    }
};