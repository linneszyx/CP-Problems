class Solution {
public:

    long long minimumReplacement(vector<int>& nums) {
        long long op = 0;
        long long pb = nums.back();
        for(auto it=nums.rbegin()+1;it!=nums.rend();++it){
            long long n=*it;
            long long n1 = (n+pb-1)/pb;
            op+=n1-1;
            pb=n/n1;
        }
        return op;
    }
};