#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main()
{
    int l,r,k;
    cin>>l>>r>>k;
    int xzp = 0;
    for (int i = l; i < r+1; i++)
    {
        if(i%k==0) xzp++;
    }
    cout<<xzp<<endl;
    
return 0;
}