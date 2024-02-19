//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
       priority_queue<int>p;
        sort(s.begin(), s.end());
        int c=1;
       // char c= s[0];
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1])
                c++;
            else{
                p.push(c);
                c=1;
            }
        }
        p.push(c);
        while(k){
            int t= p.top();
            t--;
            k--;
            p.pop();
            p.push(t);
        }
        int ans=0;
        while(!p.empty()){
            ans+=p.top()*p.top();
            p.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends