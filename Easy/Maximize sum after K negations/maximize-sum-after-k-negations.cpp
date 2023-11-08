//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int st[], int n, int k)
    {
              sort(st+0,st+n);
        for(int i=0;i<n and k>0;i++)
        {
            if( st[i] < 0)
            {
                st[i] = -1*st[i];
                k--;
            }
        }
        if(k>0)
        {
            long long int sum = accumulate(st+0,st+n,0ll);
            if(k%2==0)
            return sum;
            else{
                int k = *min_element(st+0,st+n);
                sum -= k;
                sum = sum - k;
                return sum;
            }
        }
        return accumulate( st+0,st+n,0ll);
    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}
// } Driver Code Ends