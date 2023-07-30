//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        int c0=0;
        int c1=0;
        int c2=0;
        for(int i=0;i<=n-1;i++){
            if(a[i]==0) c0++;
            else if(a[i]==1) c1++;
            else if(a[i]==2) c2++;
        }
        for(int i=0;i<=n-1;i++){
            if(c0>0) {
                a[i] = 0;
                c0--;
            }
            else if(c1>0) {
                a[i] = 1;
                c1--;
            }
            else if(c2>0) {
                a[i] = 2;
                c2--;
            }
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends