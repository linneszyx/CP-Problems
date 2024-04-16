//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        // code here
        vector<int> smin(n),smax(n);
        int maxi = arr[n-1],mini=arr[n-1];
        for(int i=n-1;i>=0;i--) {
            mini = min(mini,arr[i]);
            maxi = max(maxi,arr[i]);
            smin[i]=mini;
            smax[i]=maxi;
        }
        int res = INT_MAX;
        int pmax = arr[0],pmin=arr[0];
        res = min(res,smax[k]-smin[k]);
        for(int i=1;i<n-k;i+=1){
            int minv = min(pmin,smin[i+k]);
            int maxv = max(pmax,smax[i+k]);
            res = min(res,maxv-minv);
            pmax  =max(pmax,arr[i]);
            pmin = min(pmin,arr[i]);
        }
        res = min(res,pmax-pmin);
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends