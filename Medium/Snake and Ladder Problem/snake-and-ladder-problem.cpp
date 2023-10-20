//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int n, int arr[]){
       vector<int>adj[30+1] ;
        for(int i=1;i<=2*n-1;i+=2){
            adj[arr[i-1]].push_back(arr[i]) ;
        } 
        int dice[] ={6,5,4,3,2,1} ;
        queue<pair<int,int>>q ;
        q.push({1,0}) ;
        vector<int>vis(31,0) ;
        vis[1] =1 ;
        while(!q.empty()){
            bool flag = false ;
            auto it=q.front() ;
            int node = it.first ;
            int step= it.second ;
            q.pop() ;
            if(node==30)return step ;
            for(int i=0;i<6;i++){
                int new_node = node+dice[i] ;
                if(new_node<=30){
                  
                for(auto pr:adj[new_node]){
                // this cell has snake or laddar     
                   if(vis[pr]==0){ 
                    
                    q.push({pr,step+1}) ;
                    vis[pr] =1 ;
                   
                   }
                   continue ; // i will go back from here with taking laddar or snake operationed cell
                }
                //for those cells who does not have snake or ladder
                if(vis[new_node]==0){
                    q.push({new_node , step+1}) ;
                }
            }
            }
        }
        return 0 ;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends