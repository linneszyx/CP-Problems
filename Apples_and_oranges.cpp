/*
Author : linneszyx
*/
#include<bits/stdc++.h>
using namespace std;
int solve1(int n, int m){
    while(n!=m){
        if(n>m) n-=m;
        else m-=n;
    }
    return n;
}
void solve(){
int a,b;
cin>>a>>b;
int x = solve1(a,b);
if(a==1) cout<<1<<endl;
else cout<<x<<endl;
}
int main(){
int t;
cin>>t;
while(t--){
solve();
}
return 0;
}