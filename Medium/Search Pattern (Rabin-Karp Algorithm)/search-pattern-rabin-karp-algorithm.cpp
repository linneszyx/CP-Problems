//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            auto val = [&](char ch){return ch - 'a' + 1;};

        const int p = 31, mod = 1e9 + 7;
        int m = pat.size(), n = txt.size();

        // Precomputing power
        vector<long> p_pow(max(m, n), 1);
        for (int i = 1; i < p_pow.size(); i++)p_pow[i] = (p_pow[i - 1] * p) % mod;

        // Store hash prefix array for the string
        vector<long> hash(n + 1, 0);
        for (int i = 0; i < n ; i++)hash[i + 1] = (hash[i] + val(txt[i]) * p_pow[i]) % mod;
            
            
        // Storing the pattern hash
        long pHash = 0;
        for (int i = 0; i < m; i++)pHash = (pHash + val(pat[i]) * p_pow[i]) % mod;

        // Sliding window
        vector<int> ans;
        for (int i = 0; i < n - m + 1; i++){
            long tHash = (hash[i + m] - hash[i] + mod) % mod;
            
            // Comparision the p_pow to the right instead of dividing to save LogN time for moudlar inverse
            if (tHash == pHash * p_pow[i] % mod)ans.push_back(i + 1);
        }

        if (ans.empty())ans.push_back(-1);
        return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends