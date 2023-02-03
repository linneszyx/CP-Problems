#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int MOD = 1e9+7;
int32_t main()
{
    int xi;
    cin>>xi;
    int arr[xi];
    for (int i = 0; i < xi; i++)
    {
        cin>>arr[i];
    }
    int res = 1;
    for (int i = 0; i < xi; i++)
    {
        res = (res*(arr[i]%MOD))%MOD;
    }
    cout<<res<<endl;
return 0;
}