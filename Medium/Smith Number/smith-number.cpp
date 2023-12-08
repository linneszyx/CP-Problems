//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
   int smithNum(int n) {
        // code here
        bool sieve[n+1];
        for(int i=0;i<=n;++i){
            if(i==0 || i==1) sieve[i] = false;
            else sieve[i] = true;
        }
        
        for(int i=2;i*i<=n;++i){
            if(sieve[i]){
                for(int j=i*i;j<=n;j+=i){
                    sieve[j] = false;
                }
            }
        }
        
        int sum = 0;
        if(!(sieve[n])){
            int og = n;
            while(og){
                sum += og%10;
                og /= 10;
            }
            
            vector<int> prime_factor;
            for(int i=2;i<=n;++i){
                while(!(n%i)){
                    prime_factor.push_back(i);
                    n /= i;
                }
            }
            
            int sum1 = 0;
            for(int i=0;i<prime_factor.size();++i){
                int a = prime_factor[i];
                while(a){
                    sum1 += a%10;
                    a /= 10;
                }
            }
            
            if(sum == sum1) return 1;
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends