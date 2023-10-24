//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
  bool ispar(string x)
    {
        stack<char> stk;
        unordered_map<char,char> hash;
        
        hash['('] = ')';
        hash['{'] = '}';
        hash['['] = ']';
        
        for(int i=0;i<x.size();i++){
            if(hash.count(x[i])){
                stk.push(x[i]);
            }else{
                if(stk.empty()) return false;
                else if(hash[stk.top()] == x[i]) stk.pop();
                else return false;
            }
        }
        return stk.empty();
    }



};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends