//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
       int left = 0, right = n-1;
        int  ans = 0;
        int leftMax = 0, rightMax = 0;
        
        while(left < right){
            if(arr[left] <= arr[right]){
                if(arr[left] > leftMax){
                    // no water store
                    leftMax = arr[left];
                }
                else{
                    // water store
                    ans += leftMax - arr[left];
                }
                left++;
            }
            else{
                if(arr[right] > rightMax){
                    // no water store
                    rightMax = arr[right];
                }
                else{
                    // water store
                    ans += rightMax - arr[right];
                }
                right--;
            }
        }
        return ans;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends