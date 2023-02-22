#include <bits/stdc++.h>
using namespace std;

/**
 * If the sum of the first two elements of the first vector is less than the sum of the first two
 * elements of the second vector, return true. Otherwise, return false
 * 
 * @param xuy vector<int> &xuy
 * @param zuy vector<int> &zuy
 */
bool comparator(vector<int> &xuy, vector<int> &zuy)
{
    if (xuy[0] + xuy[1] == zuy[0] + zuy[1])
        return xuy[0] < zuy[0];
    else
        return xuy[0] + xuy[1] < zuy[0] + zuy[1];
}

/**
 * It takes in two arrays, sorts them in a way that the first array is sorted in ascending order and
 * the second array is sorted in descending order, and then it finds the maximum number of elements
 * that can be taken from the arrays such that the sum of the elements of the first array and the
 * second array is less than or equal to a given number
 */
void waoiffui()
{

    int numerio, k;
    cin >> numerio >> k;
    vector<int> xuy(numerio), zuy(numerio);
    for (int iter = 0; iter < numerio; iter++)
    {
        cin >> xuy[iter];
    }
    for (int iter = 0; iter < numerio; iter++)
    {
        cin >> zuy[iter];
    }

    vector<vector<int>> victor;

    for (int iter = 0; iter < numerio; iter++)
    {
        victor.push_back({xuy[iter], zuy[iter]});
    }
    sort(victor.begin(), victor.end(), comparator);
    int maxi = 0;
    int sigma = 0;
    int iter = 0;
    while (iter < numerio)
    {
        if (victor[iter][0] + victor[iter][1] + sigma <= k)
        {
            sigma += victor[iter][0] + victor[iter][1];
            maxi = max(maxi, victor[iter][1]);
            iter++;
        }
        else
            break;
    }

    vector<int> vicx(numerio);

    for (int k = numerio - 1; k >= 0; k--)
    {
        if (k == numerio - 1)
            vicx[k] = victor[k][0];
        else
            vicx[k] = min(vicx[k + 1], victor[k][0]);
    }
    int ans = iter;
    if (iter < numerio)
    {
        int rem = k - sigma;
        if (vicx[iter] <= rem)
            ans++;
        else if (rem + maxi >= victor[iter][0] + victor[iter][1])
        {
            ans++;
        }
    }
    cout << ans << endl;
}

int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        waoiffui();
    }
}
