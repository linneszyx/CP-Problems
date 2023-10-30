//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    string rremove(string s){
          if(s.size()==0)
        return s;
        if(s.size()==1)
        return s;
        string temp="";
        int flag=0;
        for(int i=1;i<s.size();)
        {
            while(s[i-1]==s[i])
            {
                flag=1;
                i++;
            }
            if(i-2>=0 && s[i-1]!=s[i] && s[i-1]==s[i-2])
            i++;
            else if(s[i-1]!=s[i])
            {
            temp+=s[i-1];
            i++;
            }
        }
        if(s[s.size()-1]!=s[s.size()-2])
        temp+=s[s.size()-1];
        if(flag==0)
        return temp;
        return rremove(temp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends