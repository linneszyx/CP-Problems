#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,x;
    cin>>n>>x;
    int victor[n];
    for(int i=0;i<n;i++){
        cin>>victor[i];
    }
    sort(victor,victor+n);
    if(n==x) cout<<victor[0]-1<<endl;
   else{
     cout<<victor[n-x]-1<<endl;
   }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}