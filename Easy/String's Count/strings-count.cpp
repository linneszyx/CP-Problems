//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int countStr(long long int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        cout << countStr(n) << endl;
    }
return 0;
}
// } Driver Code Ends


long long int countStr(long long int n){
    //complete the function here
    long long int ans = 1;
    ans += 2*n; //for one b or one c
    if(n>=2)
    {
        long long int temp =  (n*(n-1))/2; 
        ans += temp; //for 2 c only
        ans += 2*temp; //for one b one c only
    }
    if(n>=3)
        ans += (n*(n-1)*(n-2))/2;   // for one b and 2 c only
    return ans;
}