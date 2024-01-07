//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int splitArray(int arr[] ,int N, int K) {
        // code here
        int totalSum = 0;
        int mx = INT_MIN;
        for(int i=0;i<N;i+=1){
            totalSum+=arr[i];
            mx = max(mx,arr[i]);
        }
        int lo = mx,hi=totalSum,ans=INT_MAX;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(isValid(arr,mid,K,N)){
                ans  = min(ans,mid);
                hi=mid-1;
            }
            else {
                lo=mid+1;
            }
        }
    }
    bool isValid(int arr[],int rs,int k,int n){
        int sum=0;
        int count=1;
        for(int i=0;i<n;i+=1){
            if(sum+arr[i]<=rs) sum+=arr[i];
            else {
                sum=arr[i];
                count++;
            }
        }
        return count<=k;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends