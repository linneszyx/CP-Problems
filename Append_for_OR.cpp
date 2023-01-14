#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,y;
    cin>>n>>y;
   int ans = 0;
   for (int i = 0; i < n; i++)
   {
    int x;
    cin>>x;
    ans |= x;
   }
   int z = y - ans;
   if((z&y)==z) cout<<z<<endl;
   else cout<<-1<<endl;
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