//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
       int left = 0, right = n-1;
        long long ans = 0;
        long long leftMax = 0, rightMax = 0;
        
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

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends