//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete below method */

class Solution{
    public:
      int dp[1000001];
    int fun(int arr[], int n, int i)
    {
        if(i+3>=n)return 0;
        
        if(dp[i]!=-1)return dp[i];
        
        int a= arr[i]+ fun(arr, n, i+1);
        int b= arr[i+1]+ fun(arr, n, i+2);
        int c= arr[i+2]+ fun(arr, n, i+3);
        int d= arr[i+3]+ fun(arr, n, i+4);
        
        
        return dp[i]= min({a, b,c,d });
        
        
    }
    int minSum(int arr[], int n){
        //Write your code here
        if(n<=4)return *min_element(arr, arr+n);
        memset(dp, -1, sizeof(dp));
        return fun(arr, n, 0);
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
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.minSum(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends