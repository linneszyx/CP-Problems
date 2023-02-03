

#include<bits/stdc++.h>
using namespace std;
void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    int k;
    for(k=1;k<100;k++){
        if(a%k!=0 and b%k!=0 and c%k!=0){
            cout<<k<<endl;
            break;
        }
    }
}
int main(){
int tc;
cin>>tc;
while(tc--){
    solve();
}
return 0;
}