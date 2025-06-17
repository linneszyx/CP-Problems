class Solution {
public:
    vector<int> asteroidCollision(vector<int>& astro) {
        int n = astro.size();
        vector<int> v;
        for(int i=0;i<n;i+=1) {
            if(astro[i]>0 or v.empty() or v.back()<0) 
                v.push_back(astro[i]);
            else if(v.back()<=-astro[i]){
                if(v.back()<-astro[i]) --i;
                v.pop_back();
            }
        }
            return v;
    }
};