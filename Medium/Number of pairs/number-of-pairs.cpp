//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
 

class Solution{
    public:
    
    // X[], Y[]: input array
    // M, N: size of arrays X[] and Y[] respectively
    //Function to count number of pairs such that x^y is greater than y^x.
    long long countPairs(int X[], int Y[], int M, int N)
    {
       sort(X,X+M);
        sort(Y,Y+N);
        int one=0;
        for(int i=0;i<N;i++) if(Y[i]==1) one++;
        long long ans=0;
        for(int i=0;i<M;i++){
            int x=X[i];
            if(x==1) continue;
            if(x==2){
                int ind=upper_bound(Y,Y+N,4)-Y;
                ans+=N-ind+one;
            }
            else if(x==3){
                int ind=upper_bound(Y,Y+N,x)-Y;
                ans+=N-ind;
                ind=upper_bound(Y,Y+N,2)-Y;
                ans+=ind;
            }
            else{
                int ind=upper_bound(Y,Y+N,x)-Y;
                ans+=N-ind+one;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int M,N;
		cin>>M>>N;
		int i,a[M],b[N];
		for(i=0;i<M;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<N;i++)
		{
			cin>>b[i];
		}
		Solution ob;
		cout<<ob.countPairs(a, b, M, N)<<endl;
	}
}
// } Driver Code Ends