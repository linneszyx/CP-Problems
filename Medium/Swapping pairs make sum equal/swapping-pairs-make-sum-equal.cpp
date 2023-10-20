//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
             int sum1=0,sum2=0; // Using Two pointers technique..!
        for(int i=0;i<n;i++)
        sum1+=A[i];
        for(int i=0;i<m;i++)
        sum2+=B[i];
        
        sort(A, A+n); 
        sort(B, B+m);
        int l=0;
        int r=0;
        int dif=abs(sum1-sum2);
        if(dif&1)return -1;
        dif/=2;
        
        while(l<n && r<m)
        {
            int curr=abs(A[l]-B[r]);
            if(dif==curr)
            return 1;
            if(curr<dif)
            r++;
            else
            l++;
        }
        return -1;
	}
 

};

//{ Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}






// } Driver Code Ends