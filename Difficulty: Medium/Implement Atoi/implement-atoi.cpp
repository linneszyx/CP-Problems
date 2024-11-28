//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define MAX INT_MAX
#define MIN INT_MIN
class Solution {
  public:
    int myAtoi(char *s) {
        long res=0;
        bool f=false;
        while(*s!='\0' and *s==' ')s++;
        if(*s=='+' or *s=='-'){
            f=(*s=='-');
            s++;
        }
        while(*s!='\0' and *s>='0' and *s<='9'){
            res=res*10+*s-'0';
            if(!f and res>MAX) return MAX;
            else if(f and (-1*res)<MIN) return MIN;
            s++;
        }
        if(f) res=-1*res;
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends