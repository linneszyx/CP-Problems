#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    if(arr[n-1]%10) cout<<"No\n";
    else cout<<"Yes\n";
return 0;
}