//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool findPair(int arr[], int size, int n){
      unordered_map<int,int>mp;
   
    for(int i=0;i<size;i++)
    {
        int val=arr[i];
       if(mp[val-n]==1||mp[val+n]==1)
       {
        
           return 1;
       }
       mp[val]=1;
    }
    return 0;
}