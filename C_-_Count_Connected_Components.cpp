#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

signed main()
{

    int N = 4000000;
    int h[N] = {0};
    for (int i = 2; i * i < N; ++i)
    {
        if (h[i] == 0)
        {
            for (int j = i * i; j < N; j += i)
            {
                h[j] = 1;
            }
        }
    }

    vector<int> v;
    for (int i = 2; i < N; ++i)
    {
        if (h[i] == 0)
            v.pb(i);
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int x;
        for (int i = 0; i < v.size(); ++i)
        {
            if (n % v[i] == 0)
            {
                x = v[i];
                break;
            }
        }

        int z = (n / x);
        int y = sqrtl(z);
        if ((y * y) == z)
        {
            cout << y << " " << x << endl;
        }
        else
        {
            cout << x << " " << (n / (x * x)) << endl;
        }
    }
}