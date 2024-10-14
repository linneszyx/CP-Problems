class Solution {
public:
    static long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(),nums.end());
        long long sc=0;
        for(int i=0;i<k;i+=1){
            int x = pq.top();
            sc+=x;
            if(x==1) {
                sc+=(k-1-i);
                break;
            }
            pq.pop();
            pq.push((x+2)/3);
        }
        return sc;
    }
};