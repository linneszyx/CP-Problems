//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define sz(x) ((int)x.size())
#define um unordered_map<int,int>
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        int n = sz(arr);
        int res=0,s=0;
        um mp;
        mp[s]=-1;
        for(int i=0;i<n;i+=1) {
            if(arr[i]==0) s+=-1;
            else s+=1;
            if(mp.find(s)!=mp.end()) res=max(res,i-mp[s]);
            else mp[s]=i;
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends