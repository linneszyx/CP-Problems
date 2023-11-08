//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
#define ll long long int
class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here     
        bool z  = false;
        int zi = -1;
        int c=0;
        ll p = 1;
        vector<ll> res(n,0);
        for(int i=0;i<n;i+=1){
            if(nums[i]!=0) p*=nums[i];
            else {
                z = true;
                zi = i;
                c+=1;
                if(c>1) return res;
            }
        }
        if(z) res[zi] = p;
        else {
            for(int i=0;i<n;i+=1) res[i] = p/nums[i];
        }
        return res;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends