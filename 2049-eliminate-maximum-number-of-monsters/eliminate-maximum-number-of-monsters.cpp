class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<float> ar;
        for(int i=0;i<dist.size();i+=1) ar.push_back((float)dist[i]/speed[i]);
        sort(ar.begin(),ar.end());
        int ans  = 0;
        for(int i=0;i<ar.size();i+=1) {
            if(ar[i]<=i) break;
            ans++;
        }
        return ans;
    }
};