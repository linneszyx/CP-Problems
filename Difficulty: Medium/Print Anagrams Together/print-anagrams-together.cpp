//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#define vs vector<string>
#define vvs vector<vs>
#define all(p) p.begin(),p.end()
class Solution {
  public:
    vvs anagrams(vs& arr) {
        unordered_map<string,vs>mp;
        vvs res;
        for(auto &str : arr ) {
        string so = str;
        sort(all(so));
        mp[so].push_back(str); }
        for(auto it : mp) res.push_back(it.second);
        sort(all(res));
        return res;}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends