

#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll N;
    cin >> N;
    int x = 0;
    while(N%2==0)
    {
        N /= 2;
        x++;
    }
    if(x%2==0) cout<<1<<endl;
    else cout<<0<<endl; 
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
     solve();
    }
    return 0;
}