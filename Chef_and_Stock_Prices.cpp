#include <bits/stdc++.h>
using namespace std;
void solve()
{
    float s, a, b, c;
    cin >> s >> a >> b >> c;

   float  s1 = s + ((s * c) / 100);
    if (s1 >= a and s1 <= b)
    {
        cout <<"YES\n";
    }
    else
    {
        cout <<"NO\n";
    }
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
