//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long minTime(int arr[], int n, int k)
    {
       long long int low = 0 , high = 0 , ans;
        for(int i = 0 ; i< n; i++){
            high += arr[i];
            low = max(low , 1ll*arr[i]);
        }
        while(low <= high){
            long long int mid = low+(high-low)/2;
            long int sum = 0 , count = 1;
            for(int i = 0 ; i< n; i++){
                sum += arr[i];
                if(sum > mid){
                    count++;
                    sum = arr[i];
                }
            }
            if(count <=k){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends