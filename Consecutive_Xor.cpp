#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int c = arr[0];
    for (int i = 1; i < n; i++)
    {
        c = c^arr[i];
    }
    if(c==0) cout<<"YES\n";
    else cout<<"NO\n"; 
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