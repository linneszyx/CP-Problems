//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
       unordered_map<int,int> mp;
       int n = arr.size()/3;
       for(int i : arr) {
           mp[i]++;
       }
       arr.clear();
       for(auto i : mp)
       {
           if(i.second>n) 
           {
               arr.push_back(i.first);
           }
       }
       if(arr.size()==2 and arr[0]>arr[1]) {
           swap(arr[0],arr[1]);
       }
       return arr;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends