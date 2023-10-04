//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
          unordered_map<char,int>m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        
        int ans=0;
        int i=0;
        for(i=0;i<str.length()-1;i++)
        {
            char ch1=str[i];
            char ch2=str[i+1];
            if(m[ch1]>=m[ch2])
           {
               ans+=m[ch1];
           }
           else 
           {
               ans+=(m[ch2]-m[ch1]);
              i++;
           }
        }
        if(i<str.length())
        {
            ans+=m[str[i]];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends