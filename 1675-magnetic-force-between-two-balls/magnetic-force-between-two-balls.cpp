class Solution {
public:
bool f(const vector<int>&arr,int dist,int balls){
    int cb=1;
    int lp=arr[0];
    for(int i=1;i<arr.size();i+=1){
        if(arr[i]-lp>=dist) {
            cb++;
            lp=arr[i];
        }
        if(cb>=balls) return true;
    }
    return false;
}
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int lo=1;
        int hi = (position.back()-position[0])/(m-1);
        int ans = 1;
        while(lo<=hi) {
            int mid = lo+(hi-lo)/2;
            if(f(position,mid,m)) {
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;
    }
};