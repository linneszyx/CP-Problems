

#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c)
        cout << "NO\n";
    else if (a + b == c)
        cout << "YES\n";
    else if (b + c == a)
        cout << "YES\n";
    else if (a + c == b)
        cout << "YES\n";
    else
        cout << "NO\n";
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