#include<bits/stdc++.h>
using namespace std;
void solve()
{
 long long  n,k;
 
 cin>>n>>k;
 if(k==0)
 cout<<n<<endl;
 else 
 cout<<n%k<<endl;
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
