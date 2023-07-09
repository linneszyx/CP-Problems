//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        long long max_area = 0;
        stack<long long> s;
        long long i = 0;
        while(i < n){
            if(s.empty() || arr[s.top()] <= arr[i]){
                s.push(i++);
            }
            else{
                long long top = s.top();
                s.pop();
                long long area = arr[top] * (s.empty() ? i : i - s.top() - 1);
                max_area = max(max_area, area);
            }
        }
        while(!s.empty()){
            long long top = s.top();
            s.pop();
            long long area = arr[top] * (s.empty() ? i : i - s.top() - 1);
            max_area = max(max_area, area);
        }
        return max_area;   
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends