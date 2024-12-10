//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define vvi vector<vector<int>>
#define vi vector<int>
#define sz(x) ((int)x.size())
#define all(p) p.begin(),p.end()
bool compare(vi &a,vi &b) {
    return a[1]<b[1];
}
class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
       sort(all(intervals),compare);
       int c=0,lt=INT_MIN;
       for(const auto &ite : intervals) {
           if(ite[0]>=lt) {
               lt=ite[1];
               c++;
           }
       }
       return sz(intervals)-c;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends