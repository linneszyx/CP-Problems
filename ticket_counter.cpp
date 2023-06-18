//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        // code here
       int q = N/K;
       int ticketIndex;
       if(q%2==1) {
        ticketIndex = ((q/2)+1) * K;
        if(N%K==0)  return ticketIndex;
        else return ticketIndex + 1;
       }
       else {
        ticketIndex = (N+1) - (q/2) * K;
        if(N%K==0) return ticketIndex;
        else return ticketIndex - 1;
       }
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends