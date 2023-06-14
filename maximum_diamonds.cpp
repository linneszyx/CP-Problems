//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long
class Solution {
  public:
    long long maxDiamonds(int A[], int N, int K) {
      priority_queue<int> maxH;
      for(int i=0;i<N;i++) maxH.push(A[i]);
      ll ans = 0;
      while(K){
          ll x = maxH.top();
          maxH.pop();
          ans+=x;
          maxH.push(x/2);
          K--;
      }
      return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.maxDiamonds(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends
