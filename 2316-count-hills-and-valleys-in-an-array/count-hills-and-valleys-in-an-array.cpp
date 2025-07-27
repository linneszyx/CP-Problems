class Solution {
public:
    int countHillValley(vector<int>& v) {
        vector<int> vv;
        vv.push_back(v[0]);
        for(int i =1;i<v.size();i+=1) 
        {
            if(v[i]!=v[i-1]) vv.push_back(v[i]);
        }
        int c=0;
        for(int i=1;i<vv.size()-1;i+=1) 
        {
            if(vv[i]>vv[i-1] and vv[i] > vv[i+1] or vv[i]<vv[i-1] and vv[i]<vv[i+1]) c++;
        }
        return c;
    }
};