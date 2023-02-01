#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a;
    vector<int> b;
    int ele;
    for (int i = 0; i < n; i++)
    {
        cin>>ele;
        a.push_back(ele);
    }
    for (int i = 0; i < m; i++)
    {
        cin>>ele;
        b.push_back(ele);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int c = 0;
    for (int i = a[n - 1]; i <= b[0]; i++)
    {
        bool flag = true;
        for (int j = 0; j < n; j++)
        {
            if (i % a[j] != 0)
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
        {
            for (int j = 0; j < m; j++)
            {
                if (b[j] % i != 0)
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag == true)
        {
            c++;
        }
    }
    cout<<c;
    return 0;
}