#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int numerio;
    cin >> numerio;

    if (numerio == 0)
    {
        cout << 1 << ' ' << 3 << ' ' << 4 << ' ' << 5 << endl;
        return;
    }
    int victor_po[4] = {};
    victor_po[0] = victor_po[1] = victor_po[2] = numerio;
    int j = 0;
    for (int i = 0; i < 60; i++)
    {
        if (!(numerio & (1ll << i)))
        {
            victor_po[j] += (1ll << i);
            if (j == 2)
                victor_po[3] += (1ll << i);
            j++;
            j %= 3;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        assert(victor_po[i] != 0);
        for (int j = i + 1; j < 4; j++)
            assert(victor_po[i] != victor_po[j]);
    }
    int val = ((victor_po[0] & victor_po[1]) | victor_po[2]) ^ victor_po[3];
    assert(val == numerio);
    if (victor_po[3] == 0)
        cout << -1 << endl;
    else
    {
        for (auto i : victor_po)
            cout << i << ' ';
        cout << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test_cases = 1;
    cin >> test_cases;
    while (test_cases--)
    {
        solve();
    }
}