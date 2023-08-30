/*
    Author : linneszyx
The only true fear is the fear of the unknown
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define F first
#define S second
#define pb push_back
#define si set<int>
#define vi vector<int>
#define pii pair<int, int>
#define vpi vector<pii>
#define vpp vector<pair<int, pii>>
#define mii map<int, int>
#define mpi map<pii, int>
#define spi set<pii>
#define endl "\n"
#define sz(x) ((int)x.size())
#define all(p) p.begin(), p.end()
#define double long double
#define que_max priority_queue<int>
#define que_min priority_queue<int, vi, greater<int>>
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define print(a)          \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl
#define print1(a)    \
    for (auto x : a) \
    cout << x.F << " " << x.S << endl
#define print2(a, x, y)         \
    for (int i = x; i < y; i++) \
        cout << a[i] << " ";    \
    cout << endl
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int fact[N];
int addm(int x, int y)
{
    return (x + y) % mod;
}
int subm(int x, int y)
{
    return ((x - y) % mod + mod) % mod;
}
int mulm(int x, int y)
{
    return (x * y) % mod;
}
int powr(int x, int y)
{
    int res = 1;
    while (y)
    {
        if (y & 1)
            res = mulm(res, x);
        y >>= 1;
        x = mulm(x, x);
    }
    return res;
}
int inv(int x)
{
    return powr(x, mod - 2);
}
void calcfact()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = mulm(fact[i - 1], i);
}
int divison(int x, int y)
{
    return mulm(x, inv(y));
}
int ncr(int n, int r)
{
    return mulm(mulm(fact[N], inv(fact[r])), inv(fact[n - r]));
}
int npr(int n, int r)
{
    return mulm(fact[n], inv(fact[n - r]));
}

void waiffuu()
{
    int x, y;
    cin >> x >> y;
    if (x > y)
        cout << "New";
    else if (x < y)
        cout << "Old";
    else
        cout << "Same";
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    while (t--)
        waiffuu();
    return 0;
}