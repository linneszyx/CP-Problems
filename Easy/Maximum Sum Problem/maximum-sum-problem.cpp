//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        int f(int n,int mx){
            if(n>n/2 + n/3+n/4) return n;
            mx = max(mx,f(n/2,mx)+f(n/3,mx)+f(n/4,mx));
        }
        int maxSum(int n)
        {
            //code here.
            int  mx=0;
            if(n==0) return 0;
            int t=f(n,mx);
            return t;
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends