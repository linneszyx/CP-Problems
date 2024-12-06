//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#define sz(x) ((int)x.size())
class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
       int c=0;
       int n = sz(citations);
       for(int i=n;i>0;i--){
           int curr=i;
           for(int j=0;j<n;j+=1) {
               if(citations[j]>=curr) c++;
           }
           if(c==curr) return c;
           else if(c>=curr) return curr;
           else c=0;
       }
       return c;
    }
};

//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.hIndex(arr);

        cout << result << endl;

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends