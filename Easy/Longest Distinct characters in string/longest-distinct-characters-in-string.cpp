//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    // your code here
     unordered_map<char,int>mp;
    int i=0,j=0;
    int maxi=INT_MIN;
    for(int i=0;i<s.length();i++){
        mp[s[i]]++;
        while(mp[s[i]]>1){
            mp[s[j]]--;
            j++;
        }
        maxi=max(maxi,i-j+1);
    }
    return maxi;
}