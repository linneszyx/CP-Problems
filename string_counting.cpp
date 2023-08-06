//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    long long int countStrings(string s)
    {
        // Your code goes here
        long long int count = 0;
        long long int n = s.size();
        unordered_set<char> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(s[i]);
        }
        count = pow(2, st.size());
        return count;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        Solution obj;
        long long int ans = obj.countStrings(s);
        cout << ans << "\size_of_str";
    }
}

// } Driver Code Ends