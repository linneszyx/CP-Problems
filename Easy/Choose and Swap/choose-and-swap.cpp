//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    void swap(char c, char d, string &a) {
        for (int i=0; i<a.size(); i++) {
            if (a[i] == c) a[i] = d;
            else if (a[i] == d) a[i] = c;
        }
    }
    string chooseandswap(string a){
        vector<bool> v(26);
        
        for (int i=0;i<a.size();i++) {
            v[a[i]-'a'] = true;
        }
        
        for (int j=0;j<a.size();j++) {
            int idx = a[j]-'a';
            v[idx] = false;
            
            int i = 0;
            while (i < idx && v[i] == false) i++;
            if (i!= idx) {
                swap('a'+i,'a'+idx,a);
                break;
            }
        }
        return a;
    }
    
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}

// } Driver Code Ends