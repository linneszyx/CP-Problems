#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int MOD = 1e9+7;
int32_t main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int res = 1;
    for (int i = 0; i < n; i++)
    {
        res = (res*(arr[i]%MOD))%MOD;
    }
    cout<<res<<endl;
return 0;
}