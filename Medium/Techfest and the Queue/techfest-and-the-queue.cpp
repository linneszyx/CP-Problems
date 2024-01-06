//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	int sumOfPowers(int a, int b){
	    // Code here
	    vector<int> sum(b+1,0);
	    vector<int> m(b+1,0);
	    auto handle = [&](int i) {
	        sum[i]=1;
	        m[i]=1;
	        for(int j=i+i;j<=b;j+=i){
	            m[j]=(j/i)%i==0 ? 1 + m[j/i]:1;
	            sum[j]+=m[j];
	        }
	    };
	    handle(2);
	    for(int i=3;i<=b;i+=2)
	    if(sum[i]==0) handle(i);
	    int ans = 0;
	    for(int i=a;i<=b;i+=1) ans+=sum[i];
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends