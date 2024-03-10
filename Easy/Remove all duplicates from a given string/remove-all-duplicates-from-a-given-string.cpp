//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	 int letters[58] = {0};
    string result = "";
    for(int i=0; i<str.length(); i++) {
        if(letters[str[i] - 65] == 0) {
            letters[str[i] - 65] = 1;
            result += str[i];
        }
    }
    return result;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends