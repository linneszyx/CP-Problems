//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
    void r(string &str) {
        int s=0,e=str.size()-1;
        while(s<e) {
            swap(str[s],str[e]);
            s++;
            e--;
        }
    }
  public:
    string roundToNearest(string str) {
        int id = str.size();
        int n = str[id-1]-'0';
        if(n<=5) {
            string ans = "";
            for(int i=0;i<id-1;i+=1) ans+=str[i];
            ans=ans+'0';
            return ans;
        }
        else {
            string ans = "";
            int sum=0;
            int carry=1;
            for(int i=id-2;i>=0;i--){
                int n=str[i]-'0'+carry;
                int ld=n%10;
                carry=n/10;
                ans+=to_string(ld);
            }
            if(carry!=0) ans+=to_string(carry);
            r(ans);
            return(ans+'0');
        }
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
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends