//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define vi vector<int>
#define sz(x) ((int)x.size())
int f(vi &arr,int tar) {
    int n = sz(arr);
    int l=0,h=n-1;
    while(l<=h) {
        int m=(l+h)/2;
        if(arr[m]==tar) return m;
        else if(arr[m]>=arr[l]) {
            if(arr[m]>=tar and arr[l]<=tar) h=m-1;
            else l=m+1;
        }
        else {
            if(arr[m]<=tar and arr[h]>=tar) l=m+1;
            else h=m-1;
        }
    }
    return -1;
}
class Solution {
  public:
    int search(vector<int>& arr, int key) {
    int x = f(arr,key);
    return x;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends