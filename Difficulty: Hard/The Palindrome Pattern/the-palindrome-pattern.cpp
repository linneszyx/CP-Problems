//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  
  private:
    bool isPalindrome(vector<int>& v){
        int n = v.size();
        int i=0;
        int j = n-1;
        
        while(i<j){
            if(v[i]!=v[j]) return false;
            i++;
            j--;
        }
        
        return true;
    }
    
  public:
    string pattern(vector<vector<int>> &arr) {
        int rows = arr.size();
        int cols = arr[0].size();
        
        //check all rows
        for(int i=0;i<rows;i++){
            if(isPalindrome(arr[i])){
                return to_string(i) + " R";
            }
        }
        
        //check cols
        for(int i=0;i<cols;i++){
            int lo=0;
            int hi = rows-1;
            bool flag = true;
            while(lo < hi){
                if(arr[lo][i]!=arr[hi][i]) {
                    flag = false;
                    break;
                }
                lo ++;
                hi--;
            }
            if(flag){
                return to_string(i) + " C";
            }
        }
        
        
        return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends