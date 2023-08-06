//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int diffSum(int n, int m, int arr[])
    {
        // write your code here
        sort(arr, arr + n, greater<int>());
        int maxDiff = 0;
        for (int i = 0; i < m; i++)
        {
            maxDiff += arr[i] - arr[n - i - 1];
        }
        return maxDiff;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.diffSum(n, m, arr);
        if (t)
            cout << endl;
    }
}
// Position this line where user code will be pasted.

// } Driver Code Ends