//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
  bool isPalindrome(string s){
        int i = 0;
        int j = s.length() - 1;
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
public:
    string longestPalindrome(string S){
        // code here
        if (S.empty()) return "";
        string longest = "";
        for (int i = 0; i < S.length(); i++) {
            for (int j = i; j < S.length(); j++) {
              string substring = S.substr(i, j - i + 1);
              if (isPalindrome(substring) && substring.length() > longest.length()){
                   longest = substring;
                }
            }
        }
        return longest;
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends