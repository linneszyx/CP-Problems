//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template 

class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
          int mod= 1e9+7; 
      
       int a=0; 
        int b=0;
         int c=0 ; 
          
           for ( auto i: s) {
                 if( i=='a') 
                 a= (2*a%mod+1) ;
                  else if(i=='b')
                    b=(2*b%mod+a)%mod;
                    else  c= (2*c%mod+b)%mod; 
           }
             return c%mod; 
    }
};

//{ Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends