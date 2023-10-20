//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
int minSwaps(vector<int>&a){
         int n = a.size();
        vector<int>v = a;
        sort(v.begin(), v.end());
        unordered_map<int, int>m;
        for (int i = 0; i < n; i++) {
            m[a[i]] = i;
        }
        int ans = 0;
        int i = 0;
        while (i < n) {
            if (a[i] != v[i]) {
                ans++;
                int s = a[i], t = v[i];
                swap(a[i], a[m[v[i]]]);
                swap(m[s], m[t]);
            }
            i++;
        }
        return ans;
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
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends