//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
       int n= str.size();
        int m= patt.size();
        unordered_map<char,int>mp;
        for(int i=0; i<m; i++){
            
            if(mp[patt[i]]==0){
                mp[patt[i]]=i;
            }
            
        }

        int mn=INT_MAX;
        for(int i=0; i<n; i++){
            if(mp.find(str[i])!=mp.end()){
                mn=min(mn,i);
            }
        }
        if(mn==INT_MAX) return -1;
        return mn;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
    cin>>t;
    while(t--)
    {
        string str;
        string patt;
        cin>>str;
        cin>>patt;
        Solution obj;
        cout<<obj.minIndexChar(str, patt)<<endl;
    }
	return 0;
}

// } Driver Code Ends