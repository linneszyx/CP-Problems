//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define vi vector<int>
#define sz(x) ((int)x.size())
bool f(vi&arr,int k,int mini) {
    int s=0,n=sz(arr),x=1;
    for(int i=0;i<n;i+=1) {
        if(arr[i]>mini) return false;
        if(s+arr[i]>mini) {
            x++;
            s=arr[i];
        }
        else s+=arr[i];
    }
    return x<=k;
}
class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        int n = sz(arr);
        if(n<k) return -1;
        int l=0,h=0;
        int res=0;
        for(int x : arr) h+=x;
        while(l<=h) {
            int m = l+(h-l)/2;
            if(f(arr,k,m)) {
                res=m;
                h=m-1;
            }
            else  l=m+1;
        }
        return res;
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
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends