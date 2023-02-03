#include<bits/stdc++.h>
using namespace std;
void solve(){
    int x;
    cin>>x;
    if(x<=70) cout<<0<<endl;
    else if(x>70 and x<=100) cout<<500<<endl;
    else cout<<2000<<endl;
}
int main()
{
    int tcc;
    cin>>tcc;
    while (tcc--)
    {
        solve();
    }
    
return 0;
}