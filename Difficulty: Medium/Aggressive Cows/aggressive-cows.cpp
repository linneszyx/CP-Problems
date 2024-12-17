//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#define vi vector<int>
#define all(p) p.begin(),p.end()
#define sz(x) ((int)x.size())
class Solution {
  public:
    bool f(vi &stalls,int k,int cd) {
        int c=1,st = stalls[0];
        for(int i=1;i<sz(stalls);i+=1) {
            int cur = stalls[i];
            if(cur-st>=cd) {
                c++;
                if(c>=k) return true;
                st=cur;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
    sort(all(stalls));
    int mini = 1;
    int maxi = stalls[sz(stalls)-1] - stalls[0];
    while(mini<=maxi) {
        int cur = mini+(maxi-mini)/2;
        if(f(stalls,k,cur)) mini=cur+1;
        else maxi=cur-1;
    }
    return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends