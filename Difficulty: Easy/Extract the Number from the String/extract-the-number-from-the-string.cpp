//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
 long long ExtractNumber(string str) {

        long long  ans=0;
        long long temp=0;
        int cnt=0;
        int val=0;
        int n=str.size();
        for(int i=0;i<n;i++)
        {
            if(str[i]==' ')
            {
                val=max(val,cnt);
                ans=max(ans,temp);
                temp=0;
            }
            int k=str[i]-'0';
            if(k==9)
            {
                cnt=0;
                temp=0;
                while(i<n && str[i]!=' ') i++;
            }
            if(k>=0 && k<9)
            {
                if(k==0) cnt++;
                temp=temp*10+k;
            }
            
        }
        ans=max(ans,temp);
        if(ans==0 && cnt==0) return -1;
        return ans;
    }


};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends