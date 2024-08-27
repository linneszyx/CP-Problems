//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
     void rightSmaller(vector<int> &arr, vector<int> &rs, int n){
        stack<int> st;
        st.push(arr[n-1]);
        int i = n-2;
        while(i >= 0){
            while(!st.empty() && st.top() >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                rs[i] = 0;
            }
            else
                rs[i] = st.top();
            st.push(arr[i]);
            i--;
        }
    }
    void leftSmaller(vector<int> &arr, vector<int> &ls, int n){
        stack<int> st;
        st.push(arr[0]);
        int i = 1;
        while(i < n){
            while(!st.empty() && st.top() >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                ls[i] = 0;
            }
            else
                ls[i] = st.top();
            st.push(arr[i]);
            i++;
        }
    }
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int mx = 0;
        int n = arr.size();
        if(n==1)
            return 0;
        vector<int> ls(n, 0);
        vector<int> rs(n, 0);
        leftSmaller(arr, ls, n);
        rightSmaller(arr, rs, n);
        for(int i=0; i<n; i++){
            mx = max(mx, abs(ls[i] - rs[i]));
        }
        return mx;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends