//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int minSubset(vector<int> &arr,int n){
            sort(arr.begin(),arr.end());
        int count=0;
        long long restsum=0,currsum=0,totsum=0;
        for(int i=0;i<n;i++)
        totsum+=arr[i];
        for(int i=n-1;i>=0;i--){
            currsum+=arr[i];
            restsum=totsum-currsum;
            if(restsum<currsum){
                count=n-i;
                break;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        cout<<ob.minSubset(Arr,N)<<endl;
    }
    return 0;
}
// } Driver Code Ends