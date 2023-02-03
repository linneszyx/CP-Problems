

#include<bits/stdc++.h>
using namespace std;
void solve()
{
 int w1,w2,x1,x2,M;
 cin>>w1>>w2>>x1>>x2>>M;
 int w = w2-w1;
 int min;
 if(x1<=x2)
 {
    min = x1*M;
 }
 else
 {
    min = x2*M;
 }
 int max;
 if(x1>=x2)
 {
    max = x1 * M;
 }
 else
 {
    max = x2*M;
 }
 if(w>=min and w<=max)
 cout<<1<<endl;
 else 
 cout<<0<<endl;

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
