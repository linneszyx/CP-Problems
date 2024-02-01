//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
      int k=1;
        int sum=0;
        if(str[0]=='-'){
            k=-1;
            str.erase(0,1);
        }
        for(int i=str.size()-1;i>=0;i--){
            if(str[i]-'0'>=0 && str[i]-'0'<=9){
                sum=sum+(str[i]-'0')*k;
                k=k*10;
            }

            else{
                return -1;
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends