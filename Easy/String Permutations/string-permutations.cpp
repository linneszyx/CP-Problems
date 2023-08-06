//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    int fact(int n){
        int fac = 1;
        while(n>0){
            fac*=n;
            n--;
        }
        return fac;
    }
    vector<string> permutation(string S)
    {
        //Your code here
        int n = S.size();
        int d = fact(n);
        vector<string> v;
        v.push_back(S);
        for(int i=0;i<d-1;i++){
            next_permutation(S.begin(),S.end());
            v.push_back(S);
        }
        sort(v.begin(),v.end());
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends