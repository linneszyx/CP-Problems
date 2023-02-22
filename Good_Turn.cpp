#include<bits/stdc++.h>
using namespace std;
/**
 * It takes two integers as input and prints YES if the sum of the two integers is greater than 6 and
 * NO otherwise.
 */
void solve(){
    int x,y;
    cin>>x>>y;
   if(x+y<=6) cout<<"NO\n";
   else cout<<"YES\n";

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}