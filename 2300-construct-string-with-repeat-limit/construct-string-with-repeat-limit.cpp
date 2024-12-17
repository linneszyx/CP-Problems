class Solution {
public:
    string repeatLimitedString(string s, int rl) {
        sort(s.rbegin(),s.rend());
        string res;
        int f=1,p=0;
        for(int i=0;i<s.size();i+=1) {
            if(!res.empty() and res.back()==s[i]) {
                if(f<rl) {
                    res+=s[i];
                    f++;
                }
                else {
                    p=max(p,i+1);
                    while(p<s.size() and s[p]==s[i]) p++;
                    if(p<s.size()) {
                        res+=s[p];
                        swap(s[i],s[p]);
                        f=1;
                    }
                    else break;
                }
            } 
            else {
                res+=s[i];
                f=1;
            }
        }
        return res;
    }
};