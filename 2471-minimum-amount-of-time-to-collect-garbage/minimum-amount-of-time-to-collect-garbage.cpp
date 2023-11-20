class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int count = 0;
        int lp=0,lm=0,lg=0;
        for(int i=0;i<garbage.size();i+=1){
            for(auto c : garbage[i]){
                count++;
                if(c=='M') lm=i;
                else if(c=='G') lg=i;
                else lp=i;
            }
        }
        for(int i=1;i<travel.size();i+=1) travel[i]+=travel[i-1];
        int ans = count;
        if(lm>0) ans+=travel[lm-1];
        if(lg>0) ans+=travel[lg-1];
        if(lp>0) ans+=travel[lp-1];
        return ans;
    }
};