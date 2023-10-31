//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
      bool isValid(string s){
     int m=s.length();
     int temp=stoi(s);
     
     if(m==0 || m>3  || (s[0]=='0' && m>1)|| temp<0 || temp>255 )return false;
     
     return true;
  }
    vector<string> genIp(string &s) {
        // Your code here
        int n=s.size();
        vector<string>ans;
        if(n>12 || n<4){
            ans.push_back("-1");
            return ans;
        }
        
        for(int i=1;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    string a=s.substr(0,i);
                    string b=s.substr(i,j-i);
                    string c=s.substr(j,k-j);
                    string d=s.substr(k,n);
                    
                    if(isValid(a) && isValid(b) && isValid(c) && isValid(d)){
                        ans.push_back(a+"."+b+"."+c+"."+d);
                    }
                }
            }
        }
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends