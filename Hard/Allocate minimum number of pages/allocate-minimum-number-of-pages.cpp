//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
   int isP(int maxi, int arr[], int n, int m){
        int cnt=0;
        int sum=0;
        for(int i=0; i<n; i++){
            if(sum+arr[i]<=maxi){
                sum+=arr[i];
            }else{
                cnt++;
                sum=arr[i];
            }
        }
        return cnt;
    }
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(N<M) return -1;
        int hi=A[0];
        int lo=A[0];
        for(int i=1; i<N; i++){
            hi+=A[i];
            lo=max(lo, A[i]);
        }
        
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isP(mid, A, N, M)>=M){
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return lo;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends