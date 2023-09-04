//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string convert(string lessthan20[20], string greaterthan20[8], int n)
    {
        string ans;
        if(n<20)
            return lessthan20[n]+ ' ';
        if(n/10!= 0)//multiple digits 😢
        {
             ans+= greaterthan20[n/10 -2];
             ans.push_back(' ');
             ans+= lessthan20[n%10];
             ans.push_back(' ');
        }
        return ans;
    }
    string convertToWords(long n) {
        // code here
        string ans = "";
        string lessthan20[]= {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
        
        string greaterthan20[]= {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
        
        int calc;
        
        calc= (n-n%(long)1e7)/(long)1e7;
        if(calc>0)
        {
            //pushing the crore values
            ans= ans+ convert(lessthan20, greaterthan20, calc);
            ans+= "crore ";
        }
        n= n%(long)1e7;
        
        calc= (n-n%(long)1e5)/(long)1e5;
        if(calc>0)
        {
            ans+= convert(lessthan20, greaterthan20, calc);
            ans+= "lakh ";
        }
        n= n%(long)1e5;
        
        calc= (n-n%(long)1e3)/(long)1e3;
        if(calc>0)
        {
            ans+= convert(lessthan20, greaterthan20, calc);
            ans+= "thousand ";
        }
        n= n%(long)1e3;
        
        calc= (n-n%(long)1e2)/(long)1e2;
        if(calc>0)
        {
            ans+= convert(lessthan20, greaterthan20, calc);
            ans+= "hundred ";
        }
        n= n%(long)1e2;
        
        calc= n;
        if(n>0)
        {
            if(!ans.empty())
                ans+= "and ";
            ans+= convert(lessthan20, greaterthan20, calc);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long n;
        cin >> n;
        Solution ob;
        auto ans = ob.convertToWords(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends