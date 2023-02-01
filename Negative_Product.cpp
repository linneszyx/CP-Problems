#include <bits/stdc++.h>
using namespace std;
int solve()
{
    int a, b, c;
    cin >> a >> b >> c;

    int a_b = a * b;
    int b_c = b * c;
    int a_c = a * c;
    if (a_b < 0 || b_c < 0 || a_c < 0)
    {
        return 1;
    }
    else if (a_b == 0 || b_c == 0 || a_c == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
    return 1;
    
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        x = solve();
        if (x == 1)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}