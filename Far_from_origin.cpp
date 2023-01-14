#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    float alex_dist;
    float bob_dist;
    int alex_dist_x, alex_dist_y;
    int bob_dist_x, bob_dist_y;
    alex_dist_x = pow((x1 - 0), 2);
    alex_dist_y = pow((y1 - 0), 2);
    bob_dist_x = pow((x2 - 0), 2);
    bob_dist_y = pow((y2 - 0), 2);
    alex_dist = sqrt(alex_dist_x + alex_dist_y);
    bob_dist = sqrt(bob_dist_x + bob_dist_y);
    if (alex_dist < bob_dist)
        cout << "BOB\n";
    else if (bob_dist < alex_dist)
        cout << "ALEX\n";
    else
        cout << "EQUAL\n";
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