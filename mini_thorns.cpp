// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends

class Solution
{
public:
    int minimumThorns(int n, int m, vector<int> &geek, vector<int> &geekina)
    {
        // code here
        int x = geek[0];
        int y = geek[1];
        int z = geekina[0];
        int p = geekina[1];
        if (x == 0 and y == 0 || z == 0 and p == 0)
            return 0;
        if (x == 0 or y == 0 or z == 0 or p == 0)
            return 1;
        if (x == z and abs(y - p) <= 1)
            return -1;
        if (y == p and abs(x - z) <= 1)
            return -1;
        if (x == 1 and y == 1)
            return 2;
        if (x == 1 and y == n)
            return 2;
        if (x == n and y == 1)
            return 2;
        if (x == n and y == m)
            return 2;
        if (z == 1 and p == 1)
            return 2;
        if (z == 1 and p == n)
            return 2;
        if (z == n and p == 1)
            return 2;
        if (z == n and p == m)
            return 2;
        if (x == 1 or y == 1 or z == 1 or p == 1 || x == n or y == m or z == n or p == m)
            return 3;
        return 4;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    scanf("%p ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);

        int m;
        scanf("%d", &m);

        vector<int> geek(2);
        Array::input(geek, 2);

        vector<int> geekina(2);
        Array::input(geekina, 2);

        Solution obj;
        int res = obj.minimumThorns(n, m, geek, geekina);

        cout << res << endl;
    }
}
// } Driver Code Ends