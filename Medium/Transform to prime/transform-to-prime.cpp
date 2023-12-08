//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
   int checkPrime(int n){
        for(int i=2; i<n; i++){
            if(n%i == 0){
                return 0;
            }
        }
        return 1;
    }
    public:
    int minNumber(int arr[],int n)
    {
         int s=0;
         for(int i=0; i<n; i++){
             s += arr[i];
         }
         int t=s;
         int d = checkPrime(s);
         while(d != 1){
             s++;
             d = checkPrime(s);
         }
         
         return (s-t);
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends