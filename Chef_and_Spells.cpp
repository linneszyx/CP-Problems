#include<bits/stdc++.h>
using namespace std;
void solve()
{
  int a,b,c;
  cin>>a>>b>>c;
  int max1 = a + b;
  int max2 = b + c;
  int max3 = a + c;
  if(max1>=max2 and max1>=max3)
    cout<<max1<<endl;
    else if(max2>=max1 and max2>=max3)
    cout<<max2<<endl;
    else 
    cout<<max3<<endl;
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
