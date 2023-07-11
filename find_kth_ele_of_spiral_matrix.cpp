//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
        int i=0,j=0;
        int count=0;
        int dir=0;
        int top=0,bottom=n-1,left=0,right=m-1;
        while(top<=bottom && left<=right)
        {
            if(dir==0)
            {
                for(i=left;i<=right;i++)
                {
                    count++;
                    if(count==k)
                    {
                        return a[top][i];
                    }
                }
                top++;
                dir=1;
            }
            else if(dir==1)
            {
                for(i=top;i<=bottom;i++)
                {
                    count++;
                    if(count==k)
                    {
                        return a[i][right];
                    }
                }
                right--;
                dir=2;
            }
            else if(dir==2)
            {
                for(i=right;i>=left;i--)
                {
                    count++;
                    if(count==k)
                    {
                        return a[bottom][i];
                    }
                }
                bottom--;
                dir=3;
            }
            else if(dir==3)
            {
                for(i=bottom;i>=top;i--)
                {
                    count++;
                    if(count==k)
                    {
                        return a[i][left];
                    }
                }
                left++;
                dir=0;
            }
        }
        return -1;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends