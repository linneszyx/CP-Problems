//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        int totalSum=0,maxRowSum=0,maxColSum=0;
        for(int i=0;i<n;i++)
        {
            int rSum=0,cSum=0;
            for(int j=0;j<n;j++)
            {
                rSum+=matrix[i][j];
                cSum+=matrix[j][i];
            }
            totalSum+=rSum;
            maxRowSum=max(maxRowSum,rSum);
            maxRowSum=max(maxRowSum,cSum);
        }
        return maxRowSum*n - totalSum;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends