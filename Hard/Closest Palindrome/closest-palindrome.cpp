//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long
class Solution {
public:
ll getNum(ll num){
    string temp=to_string(num);
    int s=0;
    int e=temp.size()-1;
    while(s<e){
        temp[e--]=temp[s++];
    }
    return stoll(temp);
}
    long long int closestPalindrome(long long int num){
        // Code here
        ll ans=getNum(num);
        if(num<10){
            return ans;
        } 
        ll maxi=1e15;
        ll gap=abs(num-ans);
        for(int i=0;i<15;i++){
            ll int val=pow(10,i);
            if((num-val)>0){
                ll temp=getNum(num-val);
                if(gap>=abs(num-temp)){
                    if(gap==abs(num-temp)){
                        ans=min(ans,temp);
                    }else{
                        ans=temp;
                    }
                }
            }
     
            if((num+val)<maxi){
              ll temp=getNum(val+num);
                if(gap>=abs(num-temp)){
                    if(gap==abs(num-temp)){
                        ans=min(ans,temp);
                    }else{
                        ans=temp;
                    }
                }
            }
        }
      
        return ans;
        
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int num;
		cin >> num;
		Solution obj;
		long long int ans = obj.closestPalindrome(num);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends