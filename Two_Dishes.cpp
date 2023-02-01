#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    int d1 = a + c;
    if((d1>=n) &&b>=n)
    {
        cout<<"YES\n";
    }
    else {
        cout<<"NO\n";
    }

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
