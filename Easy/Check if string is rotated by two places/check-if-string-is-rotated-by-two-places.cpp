//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// #define all(x) (p.begin())
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        string str = str1;
        reverse(str.begin(),str.begin()+2);
        reverse(str.begin()+2,str.end());
        reverse(str.begin(),str.end());
        int x = str.length()-2;
        reverse(str1.begin(),str1.begin()+x);
        reverse(str1.begin()+x,str1.end());
        reverse(str1.begin(),str1.end());
        if(str==str2 || str1==str2) return true;
        else return false;

    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends