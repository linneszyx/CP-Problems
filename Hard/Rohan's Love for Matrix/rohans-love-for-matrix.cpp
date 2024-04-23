//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int firstElement(int n) {
         int a00 = 1;
        int a01 = 1;
        int a10 = 1;
        int a11 = 0;
        int b00 = 1;
        int b01 = 1;
        int b10 = 1;
        int b11 = 0;
        if(n == 1)
            return a10;
        for(int i = 2; i <= n; i++)
        {
            int left  = b10 * a00 + b11 * a10;
            int right = b10 * a01 + b11 * a11;
            b10 = left%1000000007;
            b11 = right%1000000007;
        }
        return b10%1000000007;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends