#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
   int s;
   s = n*(n+1)/2;
   if(s%2==0)
   {
    cout<<n<<endl;
   }
   else
   {
    cout<<n-1<<endl;
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
