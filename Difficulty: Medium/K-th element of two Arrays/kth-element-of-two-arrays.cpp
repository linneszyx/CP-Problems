//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
      int i=0,j=0;
        int mn = INT_MAX;
        if(k==1)return min(a[0],b[0]);
        int n=a.size(),m=b.size();
        
        while(i<n && j<m){
            int e1 = a[i];
            int e2 = b[j];
            k--;
            if(e1>e2){
                if(k==0)return b[j];
                j++;
            }
            else{
                if(k==0)return a[i];
                i++;
            }
        }
        
        while(i<n){
            k--;
            if(k==0)return a[i];
            i++;
        }
        
        while(j<m){
            k--;
            if(k==0)return b[j];
            j++;
        }
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends