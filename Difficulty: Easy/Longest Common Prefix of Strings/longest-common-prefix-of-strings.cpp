//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
    
    
        // your code here
        sort(arr.begin(),arr.end());
        string a = arr[0];
        string b = arr[arr.size()-1];
        int i=0;
        string ans= "";
        char ch;
        while(i<a.size()) {
            if(a[i]==b[i]) {
                ans+=a[i];
                i+=1;
            }
            else break;
        }
        if(ans.size()==0) return "-1";
        else return ans;
        
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends