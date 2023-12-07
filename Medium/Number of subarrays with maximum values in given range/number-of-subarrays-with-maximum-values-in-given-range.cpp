//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int a[], int n, int l, int r) {
        long count = 0, pre = 0, preLow = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] < l) {
                count += pre;
                preLow++;
            } else if(a[i] > r)
                pre = preLow = 0;
            else {
                count += (pre + preLow + 1);
                pre += preLow + 1;
                preLow = 0;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends