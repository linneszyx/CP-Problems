//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
int maxSubstring(string s)
    {
        // Your code goes here
        vector<int> arr;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                arr.push_back(-1);
            }
            else{
                arr.push_back(1);
            }
        }
        //apply kadanes algorithm
        int maxSum=INT_MIN;
        int curSum=0;
        for(int i=0;i<arr.size();i++){
            curSum=curSum+arr[i];
            if(curSum>maxSum){
                maxSum=curSum;
            }
            if(curSum<0){
                curSum=0;
            }
        }
        return maxSum;
    }
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends