//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
typedef long long ll;
class Solution
{
public:
    long long sumOfDivisors(int n)
    {
            ll sum=0;
       for(ll i=1;i<=n;i++)
       {
          
           ll d=n/i;
           sum+=(d*i);
       }
       return sum;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        long long ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends