class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        auto [q,r] = div(s.size(),k);
        vector<string> res(q+(r>0));
        for(int i=0;i<q;i+=1) res[i] = s.substr(i*k,k);
        if(r>0) {
            res.back() = s.substr(q*k);
            res.back()+= string(k-r,fill);
        }
        return res;
    }
};