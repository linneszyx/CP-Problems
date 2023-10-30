//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  vector<int> x;
vector<int> sortedArrayToBST(vector<int>& nums,int start,int end) {
        // Code here
        if(start>end)
        return x;
        int mid=(start+end)/2;
        x.push_back(nums[mid]);
        sortedArrayToBST(nums,start,mid-1);
        sortedArrayToBST(nums,mid+1,end);
        return x;
        
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        return sortedArrayToBST(nums,0,nums.size()-1);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends