//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
vector<string> v;
void f(int n0,int n1,string s,int n){
    if(s.length()==n){
        if(n1>=n0) {
            v.push_back(s);
            return;
        }
    }
    if(n1>=n0){
        f(n0,n1+1,s+"1",n);
        f(n0+1,n1,s+"0",n);
    }
}
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    f(0,0,"",n);
	    return v;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends