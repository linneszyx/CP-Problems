//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
      if(arr.empty())return 0;
      unordered_set<int> x(arr.begin(),arr.end());
      int l=0;
      for(int xx : x) {
          if(x.find(xx-1)==x.end()) {
              int xxx= xx;
              int xi = 1;
              while(x.find(xxx+1)!=x.end()) {
                  xxx+=1;
                  xi+=1;
              }
              l=max(l,xi);
          }
      }
      return l;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends