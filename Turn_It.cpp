#include <bits/stdc++.h>
using namespace std;
void solve()
{
    float u, v, a, s;
    cin >> u >> v >> a >> s;
    float exp = sqrt((u * u) - (2 * a * s));
    if (v < exp)
        cout <<"NO\n";
    else
        cout <<"YES\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}