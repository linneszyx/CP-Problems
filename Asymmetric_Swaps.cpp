#include <bits/stdc++.h>
using namespace std;
#define ll long long

void pppsdspd()
{
    int n;
    cin >> n;
    vector<ll int> v;
    for (int i = 0; i < 2*n; i++)
    {
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    sort(v.begin(),v.end());
    ll int spdps = 1e9;
    for (int i = 0; i <= n; i++)
    {
        spdps = min(spdps,v[n+i-1]-v[i]);
    }
    cout<<spdps<<endl;
}
int main()
{
    int test_case;
    cin >> test_case;
    while (test_case--)
    {
        pppsdspd();
    }
    return 0;
}