//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  Class Solution to contain the method for solving the problem.
class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        // code here
        long long int s=0;
        for(int i=0;i<arr.size();i+=1) s+=arr[i];
        if(s%3) return {-1,-1};
        int sv=s/3;
        int ps=0;
        vector<int> v;
        for(int i=0;i<arr.size();i+=1) {
            ps+=arr[i];
            if(ps==sv) {
                if(v.size()==0) {
                    v.push_back(0);
                    v.push_back(i);
                }
                ps=0;
            }
            else if(ps>sv) return {-1,-1};
        }
        return v;
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
        vector<int> result = ob.findSplit(arr);

        // Output result
        if (result[0] == -1 && result[1] == -1) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
    }
    return 0;
}

// } Driver Code Ends