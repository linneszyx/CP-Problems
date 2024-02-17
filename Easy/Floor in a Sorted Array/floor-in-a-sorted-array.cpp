//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> A, long long N, long long X){
        
        int low = 0;
           int high = N-1;
           while(low <= high)
              
         {    
             int mid = (low +high)/2;
              
              if(X== A[mid])
            return mid;
              if(X>A[mid])
               {  if(mid == N-1)
                     return mid;
                 if(X < A[mid+1])
                     return mid;
                 low = mid+1;}
              if(X<A[mid])
                  high = mid-1;
         }
              
             
           return -1;
        
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends