//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
  bool isPalindrome(string s){
      int i=0;
      int j=s.size()-1;
      while((i<=j)){
      if(s[i]!=s[j]){
          return false;
      }
      i++;
      j--;
  }
  return true;
  }
    bool palindromepair(int N, string arr[]) {
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i!=j && arr[i][0]==arr[j][arr[j].size()-1]){
              if(isPalindrome(arr[i]+arr[j])){
                        return true;
                    }
                }
        }
        }
        return false;
}
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        string arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.palindromepair(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends