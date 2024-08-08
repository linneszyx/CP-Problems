//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
      int i=0,j=0;
        int mn = INT_MAX;
        if(k==1)return min(arr1[0],arr2[0]);
        int n=arr1.size(),m=arr2.size();
        
        while(i<n && j<m){
            int e1 = arr1[i];
            int e2 = arr2[j];
            k--;
            if(e1>e2){
                if(k==0)return arr2[j];
                j++;
            }
            else{
                if(k==0)return arr1[i];
                i++;
            }
        }
        
        while(i<n){
            k--;
            if(k==0)return arr1[i];
            i++;
        }
        
        while(j<m){
            k--;
            if(k==0)return arr2[j];
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
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends