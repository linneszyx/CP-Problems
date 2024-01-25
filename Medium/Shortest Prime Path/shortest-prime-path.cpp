//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
   bool isPrime(int n){
        if(n<=1){
            return false;
        }
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    int solve(int Num1,int Num2)
    {   
     string str1=to_string(Num1);
     string str2=to_string(Num2);
     
     
     vector<int>vis(1e4,0);
     queue<pair<string,int>>q;
     q.push({str1,0});
     while(!q.empty())
     {
         string str=q.front().first;
         int steps=q.front().second;
         q.pop();
         if(str==str2) return steps;
         for(int i=0;i<str.size();i++)
         {
             char ch=str[i];
             for(int j=0;j<10;j++)
             {
                 if(i==0 && j==0) continue;
                 str[i]=char(j+'0');
                 int n=stoi(str);
                 if(isPrime(n)&&!vis[n])
                 {
                     q.push({str,steps+1});
                     vis[n]=1;
                 }
             }
             str[i]=ch;
         }
     }
     
     return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int Num1,Num2;
      cin>>Num1>>Num2;
      Solution obj;
      int answer=obj.solve(Num1,Num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends