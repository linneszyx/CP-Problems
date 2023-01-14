#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int a[n];
    int sum_odd = 0, sum_even = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i % 2 == 0)
            sum_even += a[i];
        else
            sum_odd += a[i];
    }
    int diff = sum_even - sum_odd;
    if (diff % 2 != 0)
        cout << "NO" << endl;
    else
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                if (a[i] < diff / 2)
                    cnt++;
            }
            else
            {
                if (a[i] > diff / 2)
                    cnt++;
            }
        }
        if (cnt > 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
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