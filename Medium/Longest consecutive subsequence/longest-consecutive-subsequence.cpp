//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
         int count=1;
      int m=INT_MIN;
      set<int> s(arr,arr+N);
      vector<int> v(s.begin(),s.end());
        if(v.size()==1) return 1;    
      for(int i=0;i<v.size()-1;i++)
      {
          if(v[i]+1==v[i+1]) count++;
          else count=1;
          m=max(m,count);
      }
      return m;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends