//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    void solve(vector<vector<int>>& newMatrix, vector<vector<int>>matrix, int crow, int ccol, int n) {
        int x=0,y=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i!=crow && j!=ccol) {
                    newMatrix[x][y++] = matrix[i][j];
                    if(y==n-1) {
                        x++,y=0;
                    }
                }
            }
        }
    }
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
        if(n==1) {
            return matrix[0][0];
        }
        vector<vector<int>>newMatrix(n-1,vector<int>(n-1,0));
        int ans=0, sign=1;
        for(int i=0;i<n;i++) {
            solve(newMatrix,matrix,0,i,n);
            ans += (sign*matrix[0][i])*determinantOfMatrix(newMatrix,n-1);
            sign = -sign;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}
// } Driver Code Ends