//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
             vector<int> ans;
        int n = arr.size();
        int negID = 1;
        for(int i=0; i<n; i++){
            if(arr[i]>=0){
                ans.push_back(arr[i]);
              
            }
        }
        int posSize = ans.size();
        int m = posSize;
        for(int i=0; i<n; i++){
            if(arr[i]<0){
                ans.push_back(arr[i]);
                
            }
        }
        int ind1 = 0;
        int ind2 = posSize;
        arr.erase(arr.begin(),arr.end());
        while(ind1 < posSize && ind2 < n){
            arr.push_back(ans[ind1]);
            ind1++;
            arr.push_back(ans[ind2]);
            ind2++;
        }
        while(ind1 < posSize) {
            arr.push_back(ans[ind1]);
            ind1++;
        }
        while(ind2 < n) {
            arr.push_back(ans[ind2]);
            ind2++;
        }
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends