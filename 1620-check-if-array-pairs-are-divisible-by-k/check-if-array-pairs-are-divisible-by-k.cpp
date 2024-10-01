class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>v(k,0);
        for(auto x : arr){
            x%=k;
            if(x<0) x+=k;
            v[x]++;
        }
        if(k%2==0 and v[k/2]%2!=0) return 0;
        int k2 = k/2-(k%2==0);
        for(int i=1;i<=k2;i+=1) {
            if(v[i]!=v[k-i]) return 0;
        }
            return 1;
    }
};