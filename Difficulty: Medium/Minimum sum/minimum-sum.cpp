//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        int idx = arr.size()-1,c=0,s=0;
        char ch;
        string str = "";
        while(idx>=0){
            s=c+arr[idx--];
            if(idx>=0) s+=arr[idx--];
            ch = ((s%10)+'0');
            str+=ch;
            c=s>=10?1:0;
        }
        if(c) str+='1';
        reverse(str.begin(),str.end());
        idx=0;
        while(idx<str.size() and str[idx]=='0') idx++;
        return idx>=str.size() ? "0" : str.substr(idx);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends