//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int solve(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int d = n % 10;
            sum + d *d;
            n = n / 10;
        }
        return sum;
    }
    bool beautifulNumber(int n)
    {
        // code here
        unordered_set<int> seen;
        while (n != 1 and seen.find(n) == seen.end())
        {
            seen.insert(n);
            n = solve(n);
        }
        return n == 1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);

        Solution obj;
        bool res = obj.beautifulNumber(n);
        if (res)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}

// } Driver Code Ends