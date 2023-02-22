
/*
Problem Statement:
Given a number N and a number X. The task is to find if there exists a valid expression with N numbers and X operations such that the value of expression is 1.

*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define SIZE 1e6 + 2
void solve()
{
    ll numer, xumer;
    cin >> numer >> xumer;
    if ((1 - numer) <= xumer and xumer <= (numer + 1))
    {
        if (xumer < 0)
        {
            ll pop_pl = abs(xumer) + 1;
            ll xop_po = numer - pop_pl;
            while (pop_pl--)
            {
                cout << "-";
            }
            while (xop_po--)
            {
                cout << "*";
            }
            cout << endl;
            return;
        }
        if (xumer > 0)
        {
            ll kop_pp = abs(xumer) - 1;
            ll xop_po = numer - kop_pp;
            while (kop_pp--)
            {
                cout << "+";
            }
            while (xop_po--)
            {

                cout << "*";
            }
            cout << endl;
            return;
        }
        if (xumer == 0)
        {
            ll xop_po = (numer - 1);
            while (xop_po--)
                cout << "*";
            cout << "-" << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}