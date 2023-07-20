#include <bits/stdc++.h>
using namespace std;
void waiffuu()
{
    int a, b, c;
    cin >> a >> b >> c;
    int f1[10] = {0};
    int f2[10] = {0};
    int f3[10] = {0};
    while (a > 0)
    {
        int rem = a % 10;
        f1[rem]++;
        a = a / 10;
    }
    while (b > 0)
    {
        int rem = b % 10;
        f2[rem]++;
        b = b / 10;
    }
    while (c > 0)
    {
        int rem = c % 10;
        f3[rem]++;
        c = c / 10;
    }
    bool flag = false;
    for (int i = 0; i < 10; i++)
    {
        if (f1[i] > 0 && f2[i] > 0 && f3[i] > 0)
        {
            cout << i << " ";
            flag = true;
        }
    }
    if (flag == false)
    {
        cout << -1;
    }
}
int main()
{
    waiffuu();
    return 0;
}