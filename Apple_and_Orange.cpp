#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s,t,a,b,n,m,d,a1=0,a2=0;
    cin>>s>>t>>a>>b>>m>>n;
    for (int i = 0; i < m; i++)
    {
        cin>>d;
        d = a+d;
        if(d>=s and d<=t) {
            a1++;
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin>>d;
        d = b+d;
        if(d>=s and d<=t) {
            a2++;
        }
    }
    cout<<a1<<endl;
    cout<<a2<<endl;
    
return 0;
}