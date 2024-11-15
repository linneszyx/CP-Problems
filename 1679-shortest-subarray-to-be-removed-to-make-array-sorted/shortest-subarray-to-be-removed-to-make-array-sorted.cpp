class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        
        int n =arr.size();
        int left=0;
        while(left+1<n and arr[left]<=arr[left+1]) left++;
        if(left==n-1) return 0;
        int right=n-1;
        while(right>0 and arr[right-1]<=arr[right]) right--;
        int r = min(n-left-1,right);
        int i=0,j=right;
        while(i<=left and j<n) {
            if(arr[i]<=arr[j]) {r=min(r,j-i-1);
            i++;}
            else j++;
        }
        return r;
    }
};