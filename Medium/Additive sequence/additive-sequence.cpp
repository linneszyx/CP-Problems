//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
    string addS(string &s1, string &s2){
        string ans="";
        int n = s1.size();
        int m  = s2.length();
        int i = n-1,j=m-1;
        int c = 0;
        while(i>=0 and j>=0){
            int val = s1[i]-'0' + s2[j]-'0' + c;
            ans.push_back(val%10 + '0');
            c = val/10;
            i--,j--;
        }
        while(i>=0){
            int val = s1[i]-'0' + c;
            ans.push_back(val%10 + '0');
            c = val/10;
            i--;            
        }
        while(j>=0){
            int val = s2[j]-'0' + c;
            ans.push_back(val%10 + '0');
            c = val/10;
            j--;            
        }
        if(c) ans.push_back(c+'0');
        reverse(ans.begin(),ans.end());
        return ans;
    }
  public:
    bool isAdditiveSequence(string s) {
        int n = s.length();
        string pre1 = "", pre2="";
        int indi = 2;
        bool flag=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n-1;j++){
                pre1 = s.substr(0,i+1);
                pre2 = s.substr(i+1,j-(i+1)+1);
                string req = addS(pre1,pre2);
                string kk = s.substr(j+1,req.length());
                if(req==kk){indi = j+1, flag=1; break;}
            }
            if(flag) break;
        }
        if(!flag) return false;
        while(indi<n){
            string req = addS(pre1,pre2);
            string kk = s.substr(indi,req.length());
            if(req != kk) return false;
            indi+=req.length();
            pre1 = pre2;
            pre2 = req;
        }
        return true;
    }
    };

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    Solution sol;

    while (t--) {
        string s;
        cin >> s;

        bool result = sol.isAdditiveSequence(s);
        cout << result << endl;
    }

    return 0;
}

// } Driver Code Ends