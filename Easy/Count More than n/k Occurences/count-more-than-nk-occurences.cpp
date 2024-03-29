//{ Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
     int countOccurence(int arr[], int n, int k) {
      int x = n/k;
        
        int cnt = 0;
        
        sort(arr,arr+n);
        
        for(int i=0;i<n;i++){
            int l = lower_bound(arr,arr+n,arr[i])-arr;
            int r = upper_bound(arr,arr+n,arr[i])-arr;
            
            if(r-l>x) cnt++;
            i = r-1;
        }
        
        return cnt;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends