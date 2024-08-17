//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
 long long int multi = 1;
        int n = nums.size();
        long long int cntzero = 0;
        bool containzeroes = false;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] != 0) multi*=nums[i];
            if(nums[i] == 0){ containzeroes = true; cntzero++;}
        } 
        vector<long long int> zeros(n , 0);
        if(containzeroes && cntzero == 1){
            for(int i = 0 ; i < n ; i++){
                if(nums[i] == 0){
                    zeros[i] = multi;
                }
            }
            return zeros; 
        }
        else if(containzeroes && cntzero >1) return  zeros;
        else{
            vector<long long int > ans(n);
            for(int i = 0 ; i < n ; i++){
                ans[i] = multi/nums[i];
            }
            return ans;
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends