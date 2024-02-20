//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
   unordered_set<string>st;
    bool f(int i, string& str){
        if(i==str.size())return true;
        string temp="";
        bool ans=false;
        for(int j=i;j<str.size();j++){
            temp+=str[j];
            if(st.find(temp)!=st.end())
                ans=ans||f(j+1,str);
        }
        return ans;
    }

    int wordBreak(string A, vector<string> &B) {
        for(int i=0;i<B.size();i++)
            st.insert(B[i]);
        return f(0,A);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends