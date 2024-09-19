//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
     int n=s.size();
        stack<string> st;
        string str="";
        for(int i=0;i<n;i++){
            if(s[i]!='.'){
                str+=s[i];
            }
            else{
            st.push(str);
            st.push(".");
            str="";
            }
        }
        while(!st.empty()){
            str+=st.top();
            st.pop();
        }
        return str;
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends