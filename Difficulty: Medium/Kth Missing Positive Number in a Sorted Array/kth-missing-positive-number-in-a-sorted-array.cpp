//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
#define sz(x) ((int)x.size())
#define vi vector<int>

int f(vi &arr,int k) {
    int s=0,e=sz(arr)-1,res=-1;
    while(s<=e) {
        int m=s+(e-s)/2;
        if((arr[m]-(m+1))<k) {
            res=m;
            s=m+1;
        }
        else e=m-1;
    }
    return res;
}
class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int x = f(arr,k);
        if(x==-1) return k;
        k=k-(arr[x]-(x+1));
        return arr[x]+k;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.kthMissing(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends