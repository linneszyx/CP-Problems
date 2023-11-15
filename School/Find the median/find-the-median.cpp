//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	public:
		int find_median(vector<int> v)
		{
		    // Code here.
		    int n = v.size();
		    sort(v.begin(),v.end());
		    int m = 0;
		    if(v.size()%2==0){
		        int m1=v[n/2-1];
		        int m2=v[n/2];
		        m = (m1+m2)/2;
		    }
		    else {
		        int x = n/2;
		        m = v[x];
		    }
		    return m;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(n);
    	for(int i = 0; i < n; i++)
    		cin>>v[i];
    	Solution ob;
    	int ans = ob.find_median(v);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends