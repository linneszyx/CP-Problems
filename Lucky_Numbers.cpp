

#include<bits/stdc++.h>
using namespace std;
void solve(){
    int x,d;
    bool flag = false;
    cin>>x;
    while(x!=0){
        d = x%10;
        if(d==7) {
            flag = true;
        }
        x/=10;
    }
    if(flag) cout<<"YES\n";
    else cout<<"NO\n";
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
return 0;
}