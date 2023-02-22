#include<bits/stdc++.h>
using namespace std;
void solve(){
  int x,y;
  cin>>x>>y;
    if(x>y) cout<<y<<endl;
    else cout<<(x+(y-x)*2)<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}