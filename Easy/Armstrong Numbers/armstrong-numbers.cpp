//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n){
        // code here
        int temp = n;
        int sumofcube = 0;
        int d;
        int sum=0,cube;
        while(n>0){
            d = n%10;
            cube = d*d*d;
            sum+=cube;
            n/=10;
        }
        if(temp==sum){
            return "Yes";
        }
        else{
            return "No";
        }
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
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends