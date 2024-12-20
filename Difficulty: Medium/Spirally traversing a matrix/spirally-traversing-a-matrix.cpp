//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
         int n=matrix.size();//row i
        int m=matrix[0].size();//col j
        int up=0;
        int right=m-1;
        int down=n-1;
        int left=0;
        int totcount=m*n;
        int count=0;
        vector<int>ans;
        
        
        while(true)
        {
            for(int j=left;j<=right;j++)
            {
                ans.push_back(matrix[up][j]);
                count++;
            }
            if(count==totcount)break;
            up++;
            for(int i=up;i<=down;i++)
            {
                ans.push_back(matrix[i][right]);
                count++;
            }
            if(count==totcount)break;
            right--;
            for(int j=right;j>=left;j--)
            {
                ans.push_back(matrix[down][j]);
                count++;
            }
            if(count==totcount)break;
            down--;
            for(int i=down;i>=up;i--)
            {
                ans.push_back(matrix[i][left]);
                count++;
            }
            if(count==totcount)break;
            left++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends