class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> c;
        int s;
        int r=0;
        for(auto i : nums) c[i]++;
        for(auto i : c){
            s = i.second;
            if(s==1) return -1;
            if(s%3==1){
                r+=(s/3)-1;
                r+=2;
            }
            else{
                r+=(s/3);
                r+=((s%3)/2);
            }
        }
        return r;
    }
};