//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr ){
	   long long val1 = 1;
        long long val2 = 1;
        long long ans = INT_MIN;
        int n = arr.size();
        for(int i=0;i<n;i++){
            
            val1 *=arr[i];
            val2 *=arr[n-1-i];
            
            ans = max(ans,max(val1,val2));
            
            if(val1 == 0) val1 = 1;
            
            if(val2 == 0) val2 = 1;
        }
        
        return ans;
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends