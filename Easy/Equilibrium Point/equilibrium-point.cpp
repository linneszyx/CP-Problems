//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
      
        
             int total=0;
        int sum=0;
        int lsum=0;
        int rsum=0;
        for(int i=0;i<n;i++)
        {
            total=total+a[i];
        }
        for(int i=0;i<n;i++)
        {
            sum=sum+a[i];
            lsum=sum-a[i];
            rsum=total-sum;
            
            if(lsum==rsum)
            {
                return i+1;
            }
        }
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends