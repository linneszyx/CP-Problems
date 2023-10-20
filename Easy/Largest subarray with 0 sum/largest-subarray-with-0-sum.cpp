//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
      int sum = 0, length=0;
        unordered_map<int,int>map;
        
        for(int i = 0;i<n;i++)
        {
            sum+=A[i];
            if(sum==0){
               length = max(length,i+1);
               continue;
            }
            
            if(map.count(sum)==0)
            map[sum]=i;
            
            else{
                length = max(length,i-map[sum]);
             }
        }
            
        return length;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends