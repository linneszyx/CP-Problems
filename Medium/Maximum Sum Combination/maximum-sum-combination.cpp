//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        priority_queue<int,vector<int>,greater<int>>q;
        vector<int>ans;
      
        
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        for(int i=N-1;i>=0;i--)
        {
            for(int j=N-1;j>=0;j--)
            {
                int sum = A[i] + B[j];
                
                 if(q.size()<K)
                 {
                      q.push(sum);
                    
                 }
                 else
                 {
                     if(sum>q.top())
                     {
                         q.pop();
                         q.push(sum);
                         
                     }
                     else
                     {
                         break;
                     }
                     
                 }
                 
            }
        }
        
        while(!q.empty())
        {
            ans.push_back(q.top());
            q.pop();
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends