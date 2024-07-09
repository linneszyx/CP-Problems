//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
         sort(arr.begin(),arr.end());
       int x=INT_MAX;
       int ans=INT_MIN;
       for(int i=0;i<arr.size()-2;i++){
           int l=i+1;
           int r=arr.size()-1;
           while(l<r){
               if(target==(arr[i]+arr[l]+arr[r])){
                   return target;
               }else if((arr[i]+arr[l]+arr[r])>target){
                   int y=abs((arr[i]+arr[l]+arr[r])-target);
                   if(x>y){
                       ans=(arr[i]+arr[l]+arr[r]);
                       x=y;
                   }else if(x==y){
                       ans=max(ans,(arr[i]+arr[l]+arr[r]));
                       x=y;
                   }
                   r--;
               }else{
                   int y=abs((arr[i]+arr[l]+arr[r])-target);
                   if(x>y){
                       ans=(arr[i]+arr[l]+arr[r]);
                       x=y;
                   }else if(x==y){
                       ans=max(ans,(arr[i]+arr[l]+arr[r]));
                       x=y;
                   }
                   l++;
               }
           }
       }
       
       return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends