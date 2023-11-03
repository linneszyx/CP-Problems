//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSingle(int N, int arr[]){
         unordered_map<int,int> um;
        for(int i=0;i<N;i++)
        {
            um[arr[i]]++;
        }
        for(int i=0;i<N;i++)
        {
            if(um[arr[i]]%2)
                return(arr[i]);
            
        }
        return(0);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.findSingle(N, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends