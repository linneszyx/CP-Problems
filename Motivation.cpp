#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int max = 0;
    int n,x;
    cin>>n>>x;
    int arr[n][2];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i][0]>>arr[i][1];
        if(arr[i][0]<=x)
        {
            if(max<arr[i][1])
            max = arr[i][1];
        }
    }
    cout<<max<<endl;
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
