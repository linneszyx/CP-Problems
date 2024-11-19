//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#define sz(x)  ((int) x.size())
#define all(p)         p.begin(), p.end()
class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        int i1=-1,i2=-1;
        stack<int> st;
        st.push(arr[sz(arr)-1]);
        int x = sz(arr)-2;
     while(x>=0 and arr[x]>=st.top()) {
         st.push(arr[x]);
         x--;
     }
     i1=x;
     if(st.size()==sz(arr)) {
         sort(all(arr));
         return;
     }
     x=sz(arr)-1;
     while(!st.empty()) {
         if(arr[i1]<st.top()) i2=x;
         arr[x]=st.top();
         x--;
         st.pop();
     }
     swap(arr[i1],arr[i2]);
        
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends