class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int> vr;
        vector<int> su = arr;
        sort(su.begin(),su.end());
        su.erase(unique(su.begin(),su.end()),su.end());
        for(int i=0;i<su.size();i+=1) vr[su[i]]=i+1;
        for(int i=0;i<arr.size();i+=1) arr[i]=vr[arr[i]];
        return arr;
    }
};