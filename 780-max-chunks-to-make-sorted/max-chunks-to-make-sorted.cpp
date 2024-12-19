class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        const int n = arr.size();
        int c=0,d=0;
        for(int i=0;i<n;i++) {
            d+=arr[i]-i;
            c+=(d==0);
        }
        return c;
    }
};